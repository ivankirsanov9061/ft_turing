#include "Handler.h"
#include "SMachineDescription.h"
#include "Reader.h"
#include "ValidatorDescription.h"
#include "MachineDescription.h"
#include "PrintDescription.h"

#include <boost/property_tree/ptree.hpp>

struct SMachineDescription ParseAndValidateMD(const std::string &json_file_path, const std::string &input_data_for_tape)
{
    std::vector<char> alphabet;
    std::vector<std::string>  states;

    boost::property_tree::ptree json_description = ReadJSONFile(json_file_path);
    auto machine_description = GetMachineDescription(json_description, alphabet, states);
    ValidateMachineDescription(input_data_for_tape, machine_description, alphabet, states);
    PrintDescription(machine_description, alphabet, states);

    return machine_description;
}
