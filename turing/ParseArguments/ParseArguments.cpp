#include "ParseArguments.h"
#include "HelpArgument.h"
#include "SafePrint.h"

#include <iostream>
#include <cstring>

struct SArguments ParseArguments(int argc, const char * const *argv)
{
    if (IsHelpArgumentGiven(argc, argv) || argc < 3)
    {
        WriteHelpInformation();
        std::exit(EXIT_SUCCESS);
    }

    if (std::strlen(argv[2]) >= 21)
    {
        Write("Argument was too long\n");
        std::exit(EXIT_FAILURE);
    }

    return {argv[1], argv[2]};
}
