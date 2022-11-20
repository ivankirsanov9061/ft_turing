#pragma once

#include "SMachineDescription.h"

#include <boost/property_tree/ptree.hpp>

struct SMachineDescription GetMachineDescription(const boost::property_tree::ptree &json_description,
                                                 std::vector<char> &alphabet,
                                                 std::vector<std::string> &states);
