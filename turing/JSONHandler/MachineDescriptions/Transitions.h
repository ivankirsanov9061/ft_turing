#pragma once

#include <map>
#include <set>
#include <boost/property_tree/ptree.hpp>

std::map<std::string, std::set<struct STransition>> GetTransitionsFromJSONDescription(boost::property_tree::ptree &json_description);
