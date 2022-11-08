#pragma once

#include <set>
#include <boost/property_tree/ptree.hpp>

std::set<char> GetAlphabetFromJSONDescription(const boost::property_tree::ptree &json_description);
