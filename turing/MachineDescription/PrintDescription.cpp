#include "PrintDescription.h"
#include "SafePrint.h"

#include <iostream>

void PrintName(const std::string &name)
{
    Write("Name: ", name, '\n');
}

void PrintAlphabet(const std::vector<char> &alphabet)
{
    Write("Alphabet: [ ");
    bool first_element = true;
    for (char chr : alphabet)
    {
        if (!first_element)
        {
            Write(", ");
        }
        first_element = false;
        Write(chr);
    }
    Write(" ]", '\n');
}

void PrintStates(const std::vector<std::string> &states)
{
    Write("States: [ ");
    bool first_element = true;
    for (auto &state : states)
    {
        if (!first_element)
        {
            Write(", ");
        }
        first_element = false;
        Write(state);
    }
    Write(" ]", '\n');
}

void PrintInitial(const std::string &initial)
{
    Write("Initial: ", initial, '\n');
}

void PrintFinals(const std::vector<std::string> &finals)
{
    Write("Finals: [ ");
    bool first_element = true;
    for (auto &final : finals)
    {
        if (!first_element)
        {
            Write(", ");
        }
        first_element = false;
        Write(final);
    }
    Write(" ]", '\n');
}

void PrintTransitions(const std::vector<std::pair<std::string, std::vector<struct STransition>>> transitions_list)
{
    for (auto &transitions : transitions_list)
    {
        for (auto &transition : transitions.second)
        {
            Write('(', transitions.first, ", ", transition.read, ')'
                     , " -> "
                     , "(", transition.to_state, ", ", transition.write, ", ");
            switch (transition.action) {
                case EAction::RIGHT:
                    Write("RIGHT");
                    break;
                case EAction::LEFT:
                    Write("LEFT");
                    break;
            }
            Write(")", '\n');
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
    Write('\n');
}
