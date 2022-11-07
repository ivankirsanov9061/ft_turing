#include "SafeStreamWriter.h"
#include "ParseArguments.h"
#include "Handler.h"
#include "SMachineDescription.h"

#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        struct SArguments arguments = ParseArguments(argc, argv, std::cout);
        struct SMachineDescription machine_description = HandleJSON(arguments.json_file_path);
        // Handle machine description here
    }
    catch (std::exception &error)
    {
        std::cerr << "Fatal error\n" <<  error.what() << std::endl;
    }
}
