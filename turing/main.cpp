#include "SafeStreamWriter/SafeStreamWriter.h"
#include "ParseArguments/ParseArguments.h"

#include <iostream>

void Run(int argc, char **argv, std::ostream &output_stream_for_information)
{
    try
    {
        struct SArguments arguments = ParseArguments(argc, argv, output_stream_for_information);
    }
    catch (std::exception &e)
    {
        output_stream_for_information << e.what() << std::endl;
    }
}

int main(int argc, char **argv)
{
    Run(argc, argv, std::cout);
}
