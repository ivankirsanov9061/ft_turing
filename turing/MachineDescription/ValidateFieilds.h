#pragma once

#include "SMachineDescription.h"

#include <vector>
#include <string>

void ValidateBlank(char blank, const std::string &input_data_for_tape, const std::vector<char> &alphabet);
void ValidateFinals(const std::vector<std::string> &finals, const std::vector<std::string> &states);
void ValidateInitial(const std::string &initial, const std::vector<std::string> &states);
void ValidateName(const std::string &name);
void ValidateTransitions(const std::vector<std::pair<std::string, std::vector<struct STransition>>> &transitions,
                         const std::vector<char> &alphabet,
                         const std::vector<std::string> &states);
