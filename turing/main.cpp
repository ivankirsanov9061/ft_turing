#include "SafeStreamWriter/SafeStreamWriter.h"
#include "ParseArguments/ParseArguments.h"

#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        struct SArguments arguments = ParseArguments(argc, argv, std::cout);
        // Use arguments variable here for JSONHandle function
    }
    catch (std::exception &error)
    {
        std::cerr << error.what() << std::endl;
    }
}
