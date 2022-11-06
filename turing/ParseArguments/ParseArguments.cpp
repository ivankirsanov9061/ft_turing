#include "ParseArguments.h"
#include "HelpArgument.h"

#include <iostream>

struct SArguments ParseArguments(int argc, const char * const *argv, std::ostream &output_stream_for_information)
{
    if (IsHelpArgumentGiven(argc, argv) || argc < 3)
    {
        WriteHelpInformation(output_stream_for_information);
        std::exit(EXIT_SUCCESS);
    }

    return {argv[1], argv[2]};
}
