#include "Initial.h"

#include <stdexcept>

void ValidateInitial(const std::string &initial, const std::set<std::string> &states)
{
    if (initial.empty())
    {
        throw std::runtime_error("Initial is empty");
    }

    if (states.find(initial) == states.end())
    {
        throw std::runtime_error("Initial does not found in the states");
    }
}
