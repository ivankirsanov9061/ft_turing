#pragma once

#include "SMachineDescription.h"

void PrintTape(const std::string &tape, size_t pos_for_mark);\
void PrintTransitionInfo(const std::string &current_state,
                         char current_chr,
                         const std::string &next_state,
                         char next_chr,
                         EAction next_action);
