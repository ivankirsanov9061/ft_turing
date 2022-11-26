#pragma once

#include <vector>
#include <boost/property_tree/ptree.hpp>

std::vector<std::pair<std::string, std::vector<struct STransition>>> GetTransitionsFromJSONDescription(const boost::property_tree::ptree &json_description);
