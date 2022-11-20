#pragma once

#include <map>
#include <set>
#include <boost/property_tree/ptree.hpp>

std::map<std::string, std::vector<struct STransition>> GetTransitionsFromJSONDescription(const boost::property_tree::ptree &json_description);
