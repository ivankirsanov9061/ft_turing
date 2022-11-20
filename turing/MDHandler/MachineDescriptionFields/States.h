#pragma once

#include <boost/property_tree/ptree.hpp>

std::vector<std::string>  GetStatesFromJSONDescription(const boost::property_tree::ptree &json_description);
