#include "PrintJob.h"
#include "SafePrint.h"

#include <iostream>

void PrintTape(const std::string &tape, size_t pos_for_mark)
{
    static const std::string yellow = "\033[1;33m";
    static const std::string usual = "\033[0m";

    safe_cout << '[';
    safe_cout.write(tape.c_str(), pos_for_mark);
    safe_cout << yellow;
    safe_cout.write(tape.c_str() + pos_for_mark, 1);
    safe_cout << usual;
    safe_cout.write(tape.c_str() + pos_for_mark + 1, tape.size() - pos_for_mark - 1);
    safe_cout << "] ";
}

void PrintTransitionInfo(const std::string &current_state,
                         char current_chr,
                         const std::string &next_state,
                         char next_chr,
                         EAction next_action)
{
    safe_cout << '(' << current_state << ", " << current_chr << ")"
              << " -> "
              << '(' << next_state << ", " << next_chr << ", ";
    switch (next_action) {
        case EAction::RIGHT:
            safe_cout << "RIGHT";
            break ;
        case EAction::LEFT:
            safe_cout << "LEFT";
            break ;
    }
    safe_cout << ")";
}
