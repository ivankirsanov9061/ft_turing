#include "PrintDescription.h"
#include "SafePrint.h"

#include <iostream>

void PrintName(const std::string &name)
{
    safe_cout << "Name: " << name << '\n';
}

void PrintAlphabet(const std::vector<char> &alphabet)
{
    safe_cout << "Alphabet: [ ";
    bool first_element = true;
    for (char chr : alphabet)
    {
        if (!first_element)
        {
            safe_cout << ", ";
        }
        first_element = false;
        safe_cout << chr;
    }
    safe_cout << " ]" << '\n';
}

void PrintStates(const std::vector<std::string> &states)
{
    safe_cout << "States: [ ";
    bool first_element = true;
    for (auto &state : states)
    {
        if (!first_element)
        {
            safe_cout << ", ";
        }
        first_element = false;
        safe_cout << state;
    }
    safe_cout << " ]" << '\n';
}

void PrintInitial(const std::string &initial)
{
    safe_cout << "Initial: " << initial << '\n';
}

void PrintFinals(const std::vector<std::string> &finals)
{
    safe_cout << "Finals: [ ";
    bool first_element = true;
    for (auto &final : finals)
    {
        if (!first_element)
        {
            safe_cout << ", ";
        }
        first_element = false;
        safe_cout << final;
    }
    safe_cout << " ]" << '\n';
}

void PrintTransitions(const std::vector<std::pair<std::string, std::vector<struct STransition>>> transitions_list)
{
    for (auto &transitions : transitions_list)
    {
        for (auto &transition : transitions.second)
        {
            safe_cout << '(' << transitions.first << ", " << transition.read << ')'
                      << " -> "
                      << "(" << transition.to_state << ", " << transition.write << ", ";
            switch (transition.action) {
                case EAction::RIGHT:
                    safe_cout << "RIGHT";
                    break;
                case EAction::LEFT:
                    safe_cout << "LEFT";
                    break;
            }
            safe_cout << ")" << '\n';
        }
    }
}

void PrintDescription(const struct SMachineDescription machine_description,
                      const std::vector<char> alphabet,
                      const std::vector<std::string>  states)
{
    PrintName(machine_description.name);
    PrintAlphabet(alphabet);
    PrintStates(states);
    PrintInitial(machine_description.initial);
    PrintFinals(machine_description.finals);
    PrintTransitions(machine_description.transitions);
    safe_cout << '\n';
}
