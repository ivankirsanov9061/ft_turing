#include "Handler.h"
#include "SMachineDescription.h"
#include "Reader.h"
#include "MDValidator.h"
#include "MachineDescription.h"

#include <boost/property_tree/ptree.hpp>

struct SMachineDescription ParseAndValidateMD(std::string &json_file_path, std::string &input_data_for_tape)
{
    std::set<char> alphabet;
    std::set<std::string> states;

    boost::property_tree::ptree json_description = ReadJSONFile(json_file_path);
    auto machine_description = GetMachineDescription(json_description, alphabet, states);
    ValidateMachineDescription(input_data_for_tape, machine_description, alphabet, states);

    return machine_description;
}
