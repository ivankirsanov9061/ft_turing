#include "MachineDescription.h"
#include "Alphabet.h"
#include "Finals.h"
#include "States.h"
#include "Transitions.h"

#include <set>

struct SMachineDescription GetMachineDescription(boost::property_tree::ptree &json_description)
{
    SMachineDescription machine_description;
    machine_description.name = json_description.get<std::string>("name");
    machine_description.blank = json_description.get<char>("blank");
    machine_description.initial = json_description.get<std::string>("initial");
    machine_description.finals = GetFinalsFromJSONDescription(json_description);
    machine_description.transitions = GetTransitionsFromJSONDescription(json_description);

    std::set<char> alphabet = GetAlphabetFromJSONDescription(json_description);
    std::set<std::string> states = GetStatesFromJSONDescription(json_description);

    return machine_description;
}
