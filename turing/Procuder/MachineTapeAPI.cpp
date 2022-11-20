#include "MachineTapeAPI.h"
#include "PrintJob.h"

std::string g_tape;
size_t g_position = 0;

void InitTape(const std::string &input_data_for_tale, char blank)
{
    g_tape = input_data_for_tale;
    if (g_tape.empty())
    {
        g_tape.insert(0, 1, blank);
    }
}

void LeftHeadShift(char blank)
{
    if (g_position != 0)
    {
        --g_position;
    }
    else
    {
        g_tape.insert(0, 1, blank);
    }
}

void RightHeadShift(char blank)
{
    ++g_position;
    if (g_position >= g_tape.size())
    {
        g_tape.insert(g_position, 1, blank);
    }
}

void RecordIntoTape(char chr)
{
    g_tape.at(g_position) = chr;
}

char GetValueOfHead()
{
    return g_tape.at(g_position);
}

size_t GetPositionOfHead() noexcept(true)
{
    return g_position;
}

void PrintStep(const std::string &current_state,
               char current_chr,
               const std::string &next_state,
               char next_chr,
               EAction next_action,
               size_t pos_for_mark)
{
    PrintTape(g_tape, pos_for_mark);
    PrintTransitionInfo(current_state, current_chr, next_state, next_chr, next_action);
    std::cout << std::endl;
}

void PrintTape()
{
    std::cout << "Final tape: ";
    PrintTape(g_tape, g_position);
    std::cout << std::endl;
}
