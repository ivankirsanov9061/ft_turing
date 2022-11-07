#pragma once

#include <set>
#include <string>

void ValidateMachineDescription(std::string &input_data_for_tape,
                                struct SMachineDescription &machine_description,
                                std::set<char> &alphabet,
                                std::set<std::string> &states);
