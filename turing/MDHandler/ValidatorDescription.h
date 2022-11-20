#pragma once

#include <vector>
#include <string>

void ValidateMachineDescription(const std::string &input_data_for_tape,
                                const struct SMachineDescription &machine_description,
                                const std::vector<char> &alphabet,
                                const std::vector<std::string> &states);
