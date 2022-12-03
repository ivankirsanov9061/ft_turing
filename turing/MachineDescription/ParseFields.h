#pragma once

#include <boost/property_tree/ptree.hpp>

std::vector<char> GetAlphabetFromJSONDescription(const boost::property_tree::ptree &json_description);
std::vector<std::string> GetFinalsFromJSONDescription(const boost::property_tree::ptree &json_description);
std::vector<std::string>  GetStatesFromJSONDescription(const boost::property_tree::ptree &json_description);
std::vector<std::pair<std::string, std::vector<struct STransition>>> GetTransitionsFromJSONDescription(const boost::property_tree::ptree &json_description);
