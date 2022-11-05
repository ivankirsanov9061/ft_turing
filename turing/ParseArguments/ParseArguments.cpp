#include "ParseArguments.h"
#include "HelpArgument.h"

#include <iostream>

struct SArguments ParseArguments(int argc, const char * const *argv)
{
    if (IsHelpArgumentGiven(argc, argv))
    {
        WriteHelpInformation();
        std::exit(EXIT_SUCCESS);
    }

    if (argc < 3)
    {
        throw std::invalid_argument("Invalid number of arguments");
    }

    return {argv[1], argv[2]};
}
