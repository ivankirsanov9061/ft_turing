#include "States.h"

std::set<std::string> GetStatesFromJSONDescription(boost::property_tree::ptree &json_description)
{
    std::set<std::string> states;
    auto states_list =  json_description.get_child("states");
    for (auto &value : states_list)
    {
        states.insert(value.second.get_value<std::string>());
    }
    return states;
}
