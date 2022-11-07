#pragma once

#include "SMachineDescription.h"

#include <boost/property_tree/ptree.hpp>

struct SMachineDescription GetMachineDescription(boost::property_tree::ptree &json_description,
                                                 std::set<char> &alphabet,
                                                 std::set<std::string> &states);
