#include "ParseFields.h"
#include "SMachineDescription.h"

std::vector<char> GetAlphabetFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::vector<char> alphabet;
    auto alphabet_list =  json_description.get_child("alphabet");
    for (auto &character : alphabet_list)
    {
        alphabet.emplace_back(character.second.get_value<char>());
    }
    return alphabet;
}

std::vector<std::string> GetFinalsFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::vector<std::string> finals;
    auto finals_list =  json_description.get_child("finals");
    for (auto &final_transition_name : finals_list)
    {
        finals.emplace_back(final_transition_name.second.get_value<std::string>());
    }
    return finals;
}

std::vector<std::string>  GetStatesFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::vector<std::string>  states;
    auto states_list =  json_description.get_child("states");
    for (auto &state_name : states_list)
    {
        states.emplace_back(state_name.second.get_value<std::string>());
    }
    return states;
}

EAction GetActionFromTransition(const boost::property_tree::ptree &transition_content)
{
    std::string action = transition_content.get<std::string>("action", "");
    if (action == "RIGHT")
    {
        return EAction::RIGHT;
    }
    else if (action == "LEFT")
    {
        return EAction::LEFT;
    }
    else
    {
        throw std::runtime_error("Unknown action in json file");
    }
}

struct STransition GetSingleTransition(boost::property_tree::ptree &transition_content)
{
    struct STransition transition;
    transition.read = transition_content.get<char>("read", '\0');
    transition.to_state = transition_content.get<std::string>("to_state", "");
    transition.write = transition_content.get<char>("write", '\0');
    transition.action = GetActionFromTransition(transition_content);

    return transition;
}

std::vector<struct STransition> GetTransitionList(boost::property_tree::ptree &transitions)
{
    std::vector<struct STransition> transition_list;
    for (auto &transition : transitions)
    {
        transition_list.push_back(GetSingleTransition(transition.second));
    }
    return transition_list;
}

std::vector<std::pair<std::string, std::vector<struct STransition>>> GetTransitionsFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::vector<std::pair<std::string, std::vector<struct STransition>>> transitions;
    auto transitions_list =  json_description.get_child("transitions");
    for (auto &transition : transitions_list)
    {
        transitions.push_back(std::make_pair(transition.first, GetTransitionList(transition.second)));
    }
    return transitions;
}

