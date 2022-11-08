#pragma once

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

boost::property_tree::ptree ReadJSONFile(const std::string &json_file_path);
