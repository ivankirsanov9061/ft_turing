#include "MachineDescription.h"
#include "MachineDescriptionFields/Alphabet.h"
#include "MachineDescriptionFields/Finals.h"
#include "MachineDescriptionFields/States.h"
#include "MachineDescriptionFields/Transitions.h"

#include <set>

struct SMachineDescription GetMachineDescription(const boost::property_tree::ptree &json_description,
                                                 std::set<char> &alphabet,
                                                 std::set<std::string> &states)
{
    SMachineDescription machine_description;
    machine_description.name = json_description.get<std::string>("name");
    machine_description.blank = json_description.get<char>("blank");
    machine_description.initial = json_description.get<std::string>("initial");
    machine_description.finals = GetFinalsFromJSONDescription(json_description);
    machine_description.transitions = GetTransitionsFromJSONDescription(json_description);

    alphabet = GetAlphabetFromJSONDescription(json_description);
    states = GetStatesFromJSONDescription(json_description);

    return machine_description;
}
