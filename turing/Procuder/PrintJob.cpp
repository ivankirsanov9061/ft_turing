#include "PrintJob.h"

#include <iostream>

void PrintTape(const std::string &tape, size_t pos_for_mark)
{
    static const std::string yellow = "\033[1;33m";
    static const std::string usual = "\033[0m";

    std::cout << '[';
    std::cout.write(tape.c_str(), pos_for_mark);
    std::cout << yellow;
    std::cout.write(tape.c_str() + pos_for_mark, 1);
    std::cout << usual;
    std::cout.write(tape.c_str() + pos_for_mark + 1, tape.size() - pos_for_mark - 1);
    std::cout << "] ";
}

void PrintTransitionInfo(const std::string &current_state,
                         char current_chr,
                         const std::string &next_state,
                         char next_chr,
                         EAction next_action)
{
    std::cout << '(' << current_state << ", " << current_chr << ")"
              << " -> "
              << '(' << next_state << ", " << next_chr << ", ";
    switch (next_action) {
        case EAction::RIGHT:
            std::cout << "RIGHT";
            break ;
        case EAction::LEFT:
            std::cout << "LEFT";
            break ;
    }
    std::cout << ")";
}
