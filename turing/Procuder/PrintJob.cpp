#include "PrintJob.h"
#include "SafePrint.h"

#include <iostream>

void PrintTape(const std::string &tape, size_t pos_for_mark)
{
    static const std::string yellow = "\033[1;33m";
    static const std::string usual = "\033[0m";

    Write('[');
    WriteString(tape.c_str(), pos_for_mark);
    Write(yellow);
    WriteString(tape.c_str() + pos_for_mark, 1);
    Write(usual);
    WriteString(tape.c_str() + pos_for_mark + 1, tape.size() - pos_for_mark - 1);
    Write("] ");
}

void PrintTransitionInfo(const std::string &current_state,
                         char current_chr,
                         const std::string &next_state,
                         char next_chr,
                         EAction next_action)
{
    Write('(', current_state, ", ", current_chr, ")"
             , " -> "
             , '(', next_state, ", ", next_chr, ", ");
    switch (next_action) {
        case EAction::RIGHT:
            Write("RIGHT");
            break ;
        case EAction::LEFT:
            Write("LEFT");
            break ;
    }
    Write(")");
}
