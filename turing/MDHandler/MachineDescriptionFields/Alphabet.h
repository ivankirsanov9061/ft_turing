#pragma once

#include <set>
#include <boost/property_tree/ptree.hpp>

std::set<char> GetAlphabetFromJSONDescription(boost::property_tree::ptree &json_description);
