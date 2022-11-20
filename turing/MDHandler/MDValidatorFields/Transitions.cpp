#include "Transitions.h"

#include <stdexcept>

void ValidateRead(char read, const std::set<char> &alphabet)
{
    if (alphabet.find(read) == alphabet.end())
    {
        throw std::runtime_error("One of read character does not found in the alphabet");
    }
}

void ValidateToState(const std::string &to_state, const std::set<std::string> &states)
{
    if (to_state.empty())
    {
        throw std::runtime_error("One of value \"to_state\" is empty");
    }

    // TODO this
    if (states.find(to_state) == states.end())
    {
        throw std::runtime_error("One of value \"to_state\" does not found in the states");
    }
}

void ValidateWrite(char write, const std::set<char> &alphabet)
{
    if (alphabet.find(write) == alphabet.end())
    {
        throw std::runtime_error("One of write character does not found in the alphabet");
    }
}

void ValidateTransitions(const std::map<std::string, std::vector<struct STransition>> &transitions,
                         const std::set<char> &alphabet,
                         const std::set<std::string> &states)
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
