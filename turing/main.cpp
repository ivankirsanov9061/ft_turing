#include "SafePrint.h"
#include "ParseArguments.h"
#include "Handler.h"
#include "SMachineDescription.h"
#include "Procuder/ProcudeMachineDescription.h"

#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        struct SArguments arguments = ParseArguments(argc, argv);
        struct SMachineDescription machine_description = ParseAndValidateMD(arguments.json_file_path, arguments.input_data_for_tape);
        ProcudeMachineDescription(arguments.input_data_for_tape, machine_description);
    }
    catch (std::exception &error)
    {
        std::cerr << "Fatal error\n" <<  error.what() << '\n';
    }
}
