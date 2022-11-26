#include "Transitions.h"

#include <algorithm>
#include <stdexcept>

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

    // TODO this
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
