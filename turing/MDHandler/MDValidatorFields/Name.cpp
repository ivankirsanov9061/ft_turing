#include "Name.h"

#include <stdexcept>

void ValidateName(const std::string &name)
{
    if (name.empty())
    {
        throw std::runtime_error("Name is empty");
    }
}
