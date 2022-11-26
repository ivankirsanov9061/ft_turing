#include "ParseArguments.h"
#include "HelpArgument.h"

#include <iostream>

struct SArguments ParseArguments(int argc, const char * const *argv)
{
    if (IsHelpArgumentGiven(argc, argv) || argc < 3)
    {
        WriteHelpInformation();
        std::exit(EXIT_SUCCESS);
    }

    return {argv[1], argv[2]};
}
