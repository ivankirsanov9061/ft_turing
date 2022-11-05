#include "SafeStreamWriter.h"

#include <iostream>
#include <cstring>

bool IsHelpArgumentGiven(int argc, const char * const *argv)
{
    for (size_t i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "-h") == 0 || std::strcmp(argv[i], "--help") == 0)
        {
            return true;
        }
    }

    return false;
}

void WriteHelpInformation()
{
    SafeStreamWrite(std::cout, "Usage: ft_turing [-h] json_file_path input_data_for_tape\n\n"
                               "Positional arguments\n"
                               "\tjson_file_path     : json description of the machine\n"
                               "\tinput_data_for_tape: input of the machine\n\n"
                               "Optional arguments\n"
                               "\t-h, --help: show this help message and exit\n");
}
