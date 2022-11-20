#pragma once

#include <set>
#include <string>

void ValidateMachineDescription(const std::string &input_data_for_tape,
                                const struct SMachineDescription &machine_description,
                                const std::set<char> &alphabet,
                                const std::set<std::string> &states);
