#include "Finals.h"

#include <stdexcept>

void ValidateFinals(const std::set<std::string> &finals, const std::set<std::string> &states)
{
    if (finals.empty())
    {
        throw std::runtime_error("Initial is empty");
    }

    for (auto &final : finals)
    {
        if (states.find(final) == states.end())
        {
            throw std::runtime_error("Some final state does not found in the states");
        }
    }
}
