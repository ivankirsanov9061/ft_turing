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

std::set<struct STransition> GetTransitionList(boost::property_tree::ptree &transitions)
{
    std::set<struct STransition> transition_list;
    for (auto &transition : transitions)
    {
        transition_list.insert(GetSingleTransition(transition.second));
    }
    return transition_list;
}

std::map<std::string, std::set<struct STransition>> GetTransitionsFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::map<std::string, std::set<struct STransition>> transitions;
    auto transitions_list =  json_description.get_child("transitions");
    for (auto &transition : transitions_list)
    {
        transitions.insert({transition.first, GetTransitionList(transition.second)});
    }
    return transitions;
}
