#include "Initial.h"

#include <algorithm>
#include <stdexcept>

void ValidateInitial(const std::string &initial, const std::vector<std::string> &states)
{
    if (initial.empty())
    {
        throw std::runtime_error("Initial is empty");
    }

    if (std::find(states.cbegin(), states.cend(), initial) == states.end())
    {
        throw std::runtime_error("Initial does not found in the states");
    }
}
