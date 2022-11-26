#include "Finals.h"

#include <algorithm>
#include <stdexcept>

void ValidateFinals(const std::vector<std::string> &finals, const std::vector<std::string> &states)
{
    if (finals.empty())
    {
        throw std::runtime_error("Initial is empty");
    }

    for (auto &final : finals)
    {
        if (std::find(states.cbegin(), states.cend(), final) == states.end())
        {
            throw std::runtime_error("Some final state does not found in the states");
        }
    }
}
