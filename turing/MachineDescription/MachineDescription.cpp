#include "MachineDescription.h"
#include "ParseFields.h"

struct SMachineDescription GetMachineDescription(const boost::property_tree::ptree &json_description,
                                                 std::vector<char> &alphabet,
                                                 std::vector<std::string> &states)
{
    SMachineDescription machine_description;
    machine_description.name = json_description.get<std::string>("name", "");
    machine_description.blank = json_description.get<char>("blank", '\0');
    machine_description.initial = json_description.get<std::string>("initial", "");
    machine_description.finals = GetFinalsFromJSONDescription(json_description);
    machine_description.transitions = GetTransitionsFromJSONDescription(json_description);

    alphabet = GetAlphabetFromJSONDescription(json_description);
    states = GetStatesFromJSONDescription(json_description);

    return machine_description;
}
