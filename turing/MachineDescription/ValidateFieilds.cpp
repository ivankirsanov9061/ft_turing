#include "ValidateFieilds.h"

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

void ValidateName(const std::string &name)
{
    if (name.empty())
    {
        throw std::runtime_error("Name is empty");
    }
}

void ValidateRead(char read, const std::vector<char> &alphabet)
{
    if (std::find(alphabet.cbegin(), alphabet.cend(), read) == alphabet.end())
    {
        throw std::runtime_error("One of read character does not found in the alphabet");
    }
}

void ValidateToState(const std::string &to_state, const std::vector<std::string> &states)
{
    if (to_state.empty())
    {
        throw std::runtime_error("One of value \"to_state\" is empty");
    }

    if (std::find(states.cbegin(), states.cend(), to_state) == states.end())
    {
        throw std::runtime_error("One of value \"to_state\" does not found in the states");
    }
}

void ValidateWrite(char write, const std::vector<char> &alphabet)
{
    if (std::find(alphabet.cbegin(), alphabet.cend(), write) == alphabet.end())
    {
        throw std::runtime_error("One of write character does not found in the alphabet");
    }
}

void ValidateTransitions(const std::vector<std::pair<std::string, std::vector<struct STransition>>> &transitions,
                         const std::vector<char> &alphabet,
                         const std::vector<std::string> &states)
{
    if (transitions.empty())
    {
        throw std::runtime_error("Transitions is empty");
    }

    for (auto &transition : transitions)
    {
        if (transition.second.empty())
        {
            throw std::runtime_error("One of transition is empty");
        }

        for (auto &transition_operation : transition.second)
        {
            ValidateRead(transition_operation.read, alphabet);
            ValidateToState(transition_operation.to_state, states);
            ValidateWrite(transition_operation.write, alphabet);
        }
    }
}
