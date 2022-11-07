#include "Handler.h"
#include "SMachineDescription.h"
#include "Reader.h"
#include "MachineDescription.h"

#include <boost/property_tree/ptree.hpp>

struct SMachineDescription HandleJSON(std::string &json_file_path)
{
    boost::property_tree::ptree json_description = ReadJSONFile(json_file_path);
    return GetMachineDescription(json_description);
}
