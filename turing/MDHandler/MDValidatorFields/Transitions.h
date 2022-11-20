#pragma once

#include "SMachineDescription.h"

void ValidateTransitions(const std::map<std::string, std::vector<struct STransition>> &transitions,
                         const std::set<char> &alphabet,
                         const std::set<std::string> &states);
