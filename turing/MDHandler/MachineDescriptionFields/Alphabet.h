#pragma once

#include <boost/property_tree/ptree.hpp>

std::vector<char> GetAlphabetFromJSONDescription(const boost::property_tree::ptree &json_description);
