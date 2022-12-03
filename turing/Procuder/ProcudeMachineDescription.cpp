#include "ProcudeMachineDescription.h"
#include "MachineTapeAPI.h"

#include <algorithm>
#include <stdexcept>

auto FindTransition(const struct SMachineDescription &machine_description, const std::string &state_name)
{
    auto transitions = std::find_if(machine_description.transitions.begin(), machine_description.transitions.end(),
                                    [&state_name](auto &lhs) { return lhs.first == state_name; });
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
    return std::find(machine_description.finals.begin(), machine_description.finals.end(), to_state) != machine_description.finals.end();
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
    char value_of_head = GetValueOfHead();
    size_t pos_of_head = GetPositionOfHead();
    PrintStep(state_name,
              value_of_head,
              transition->to_state,
              transition->write,
              transition->action,
              pos_of_head);
    RecordIntoTape(transition->write);
    DoShift(transition->action, machine_description.blank);
    if (IsFinalState(machine_description, transition->to_state))
    {
        PrintTape();
        return ;
    }
    DoTransition(machine_description, transition->to_state);
}

void ProcudeMachineDescription(const std::string &input_data_for_tape, const struct SMachineDescription &machine_description)
{
    InitTape(input_data_for_tape, machine_description.blank);
    DoTransition(machine_description, machine_description.initial);
}
