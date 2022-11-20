#pragma once

#include "SMachineDescription.h"

void PrintDescription(const struct SMachineDescription machine_description,
                      const std::set<char> alphabet,
                      const std::set<std::string> states);
