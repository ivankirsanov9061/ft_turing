#pragma once

#include <map>
#include <boost/property_tree/ptree.hpp>

std::map<std::string, struct STransition> GetTransitionsFromJSONDescription(boost::property_tree::ptree &json_description);
