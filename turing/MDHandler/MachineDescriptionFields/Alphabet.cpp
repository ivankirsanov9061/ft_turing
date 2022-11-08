#include "Alphabet.h"

std::set<char> GetAlphabetFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::set<char> alphabet;
    auto alphabet_list =  json_description.get_child("alphabet");
    for (auto &character : alphabet_list)
    {
        alphabet.insert(character.second.get_value<char>());
    }
    return alphabet;
}
