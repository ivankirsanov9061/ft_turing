#include "MachineTapeAPI.h"

std::string g_tape;
size_t g_position = 0;

void InitTape(const std::string &input_data_for_tale)
{
    g_tape = input_data_for_tale;
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

void PrintTape()
{
    std::cout << g_tape << std::endl;
}
