#include "SafeStreamWriter/SafeStreamWriter.h"
#include "ParseArguments/ParseArguments.h"

#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        struct SArguments arguments = ParseArguments(argc, argv);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
