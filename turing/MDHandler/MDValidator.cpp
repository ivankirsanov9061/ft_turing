#include "MDValidator.h"
#include "SMachineDescription.h"
#include "MDValidatorFields/Name.h"
#include "MDValidatorFields/Blank.h"
#include "MDValidatorFields/Initial.h"
#include "MDValidatorFields/Finals.h"
#include "MDValidatorFields/Transitions.h"

#include <stdexcept>

void ValidateAlphabet(const std::set<char> &alphabet)
{
    if (alphabet.empty())
    {
        throw std::runtime_error("Alphabet is empty");
    }
}

void ValidateStates(const std::set<std::string> &states,
                    const std::set<std::string> &finals,
                    const std::map<std::string, std::vector<struct STransition>> &transitions)
{
    if (states.empty())
    {
        throw std::runtime_error("States is empty");
    }

    for (auto &state : states)
    {
        if (state.empty())
        {
            throw std::runtime_error("One of states is empty");
        }
    }

    if (finals.size() + transitions.size() != states.size())
    {
        throw std::runtime_error("Finals and transitions size must be equal states size");
    }
}

void ValidateInput(const std::string &input_data_for_tape, const std::set<char> &alphabet)
{
    for (auto &character : input_data_for_tape)
    {
        if (alphabet.find(character) == alphabet.end())
        {
            throw std::runtime_error("Character from input does not found in the alphabet");
        }
    }
}

void ValidateMachineDescription(const std::string &input_data_for_tape,
                                const struct SMachineDescription &machine_description,
                                const std::set<char> &alphabet,
                                const std::set<std::string> &states)
{
    ValidateAlphabet(alphabet);
    ValidateStates(states, machine_description.finals, machine_description.transitions);
    ValidateInput(input_data_for_tape, alphabet);

    ValidateName(machine_description.name);
    ValidateBlank(machine_description.blank, input_data_for_tape, alphabet);
    ValidateInitial(machine_description.initial, states);
    ValidateFinals(machine_description.finals, states);
    //ValidateTransitions(machine_description.transitions, alphabet, states);
}
