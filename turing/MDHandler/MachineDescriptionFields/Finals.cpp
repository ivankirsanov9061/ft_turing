#include "Finals.h"

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
