#include "States.h"

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
