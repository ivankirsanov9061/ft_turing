#pragma once

#include <set>
#include <boost/property_tree/ptree.hpp>

std::set<std::string> GetFinalsFromJSONDescription(const boost::property_tree::ptree &json_description);
