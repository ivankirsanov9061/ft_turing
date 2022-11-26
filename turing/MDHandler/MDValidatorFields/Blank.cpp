#include "Blank.h"

#include <algorithm>
#include <stdexcept>

void ValidateBlank(char blank, const std::string &input_data_for_tape, const std::vector<char> &alphabet)
{
    if (std::find(alphabet.cbegin(), alphabet.cend(), blank) == alphabet.end())
    {
        throw std::runtime_error("Blank does not found in the alphabet");
    }

    if (input_data_for_tape.find(blank) != std::string::npos)
    {
        throw std::runtime_error("Blank found in the input data");
    }
}
