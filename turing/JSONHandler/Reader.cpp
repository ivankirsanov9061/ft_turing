#include "Reader.h"

boost::property_tree::ptree ReadJSONFile(std::string &json_file_path)
{
    boost::property_tree::ptree tree;
    boost::property_tree::read_json(json_file_path, tree);
    return tree;
}
