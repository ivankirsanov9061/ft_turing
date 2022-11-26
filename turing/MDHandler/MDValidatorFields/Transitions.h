#pragma once

#include "SMachineDescription.h"

void ValidateTransitions(const std::vector<std::pair<std::string, std::vector<struct STransition>>> &transitions,
                         const std::vector<char> &alphabet,
                         const std::vector<std::string> &states);
