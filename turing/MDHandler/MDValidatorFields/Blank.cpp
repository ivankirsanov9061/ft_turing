#include "Blank.h"

#include <stdexcept>

void ValidateBlank(char blank, const std::string &input_data_for_tape, const std::set<char> &alphabet)
{
    if (alphabet.find(blank) == alphabet.end())
    {
        throw std::runtime_error("Blank does not found in the alphabet");
    }

    if (input_data_for_tape.find(blank) != std::string::npos)
    {
        throw std::runtime_error("Blank found in the input data");
    }
}
