#include "PrintDescription.h"

#include <iostream>

void PrintName(const std::string &name)
{
    std::cout << "Name: " << name << std::endl;
}

void PrintAlphabet(const std::set<char> &alphabet)
{
    std::cout << "Alphabet: [ ";
    bool first_element = true;
    for (char chr : alphabet)
    {
        if (!first_element)
        {
            std::cout << ", ";
        }
        first_element = false;
        std::cout << chr;
    }
    std::cout << " ]" << std::endl;
}

void PrintStates(const std::set<std::string> &states)
{
    std::cout << "States: [ ";
    bool first_element = true;
    for (auto &state : states)
    {
        if (!first_element)
        {
            std::cout << ", ";
        }
        first_element = false;
        std::cout << state;
    }
    std::cout << " ]" << std::endl;
}

void PrintInitial(const std::string &initial)
{
    std::cout << "Initial: " << initial << std::endl;
}

void PrintFinals(const std::set<std::string> &finals)
{
    std::cout << "Finals: [ ";
    bool first_element = true;
    for (auto &final : finals)
    {
        if (!first_element)
        {
            std::cout << ", ";
        }
        first_element = false;
        std::cout << final;
    }
    std::cout << " ]" << std::endl;
}

void PrintTransitions(const std::map<std::string, std::vector<struct STransition>> transitions_list)
{
    for (auto &transitions : transitions_list)
    {
        for (auto &transition : transitions.second)
        {
            std::cout << '(' << transitions.first << ", " << transition.read << ')'
                      << " -> "
                      << "(" << transition.to_state << ", " << transition.write << ", ";
            switch (transition.action) {
                case EAction::RIGHT:
                    std::cout << "RIGHT";
                    break;
                case EAction::LEFT:
                    std::cout << "LEFT";
                    break;
            }
            std::cout << ")" << std::endl;
        }
    }
}

void PrintDescription(const struct SMachineDescription machine_description,
                      const std::set<char> alphabet,
                      const std::set<std::string> states)
{
    PrintName(machine_description.name);
    PrintAlphabet(alphabet);
    PrintStates(states);
    PrintInitial(machine_description.initial);
    PrintFinals(machine_description.finals);
    PrintTransitions(machine_description.transitions);
    std::cout << std::endl;
}
