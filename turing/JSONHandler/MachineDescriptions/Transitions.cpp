#include "Transitions.h"
#include "SMachineDescription.h"

struct STransition GetSingleTransition()
{

}

std::map<std::string, struct STransition> GetTransitionsFromJSONDescription(boost::property_tree::ptree &json_description)
{
    std::map<std::string, struct STransition> transitions;
    auto transitions_list =  json_description.get_child("transitions");
    for (auto &value : transitions_list)
    {

    }
    return transitions;
}
