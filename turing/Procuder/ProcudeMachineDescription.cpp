#include "ProcudeMachineDescription.h"
#include "MachineTapeAPI.h"

#include <algorithm>
#include <stdexcept>

auto FindTransition(const struct SMachineDescription &machine_description, const std::string &state_name)
{
    auto transitions = machine_description.transitions.find(state_name);
    auto transition = std::find_if(transitions->second.begin(), transitions->second.end(),
                                   [](const STransition &lhs) { return lhs.read == GetValueOfHead(); });
    if (transition == transitions->second.end())
    {
        throw std::runtime_error("Machine turing was blocked");
    }
    return transition;
}

bool IsFinalState(const struct SMachineDescription &machine_description, const std::string &to_state)
{
    return machine_description.finals.find(to_state) != machine_description.finals.end();
}

void DoShift(EAction action, char blank)
{
    switch (action)
    {
        case EAction::RIGHT:
            RightHeadShift(blank);
            break ;
        case EAction::LEFT:
            LeftHeadShift(blank);
            break ;
    }
}

void DoTransition(const struct SMachineDescription &machine_description, const std::string &state_name)
{
    auto transition = FindTransition(machine_description, state_name);
    RecordIntoTape(transition->write);
    DoShift(transition->action, machine_description.blank);
    if (IsFinalState(machine_description, transition->to_state))
    {
        return ;
    }
    DoTransition(machine_description, transition->to_state);
}

void ProcudeMachineDescription(const std::string &input_data_for_tape, const struct SMachineDescription &machine_description)
{
    InitTape(input_data_for_tape);
    DoTransition(machine_description, machine_description.initial);
}
