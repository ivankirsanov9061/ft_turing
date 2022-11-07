#include "Finals.h"

std::set<std::string> GetFinalsFromJSONDescription(boost::property_tree::ptree &json_description)
{
    std::set<std::string> finals;
    auto finals_list =  json_description.get_child("finals");
    for (auto &value : finals_list)
    {
        finals.insert(value.second.get_value<std::string>());
    }
    return finals;
}
