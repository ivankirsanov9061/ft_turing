#include "Transitions.h"
#include "SMachineDescription.h"

EAction GetActionFromTransition(const boost::property_tree::ptree &transition_content)
{
    std::string action = transition_content.get<std::string>("action");
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
    transition.read = transition_content.get<char>("read");
    transition.to_state = transition_content.get<std::string>("to_state");
    transition.write = transition_content.get<char>("write");
    transition.action = GetActionFromTransition(transition_content);

    return transition;
}

std::vector<struct STransition> GetTransitionList(boost::property_tree::ptree &transitions)
{
    std::vector<struct STransition> transition_list;
    for (auto &transition : transitions)
    {
        transition_list.emplace_back(GetSingleTransition(transition.second));
    }
    return transition_list;
}

std::vector<std::pair<std::string, std::vector<struct STransition>>> GetTransitionsFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::vector<std::pair<std::string, std::vector<struct STransition>>> transitions;
    auto transitions_list =  json_description.get_child("transitions");
    for (auto &transition : transitions_list)
    {
        transitions.emplace_back(std::make_pair(transition.first, GetTransitionList(transition.second)));
    }
    return transitions;
}
