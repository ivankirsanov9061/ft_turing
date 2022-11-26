#include "Alphabet.h"

std::vector<char> GetAlphabetFromJSONDescription(const boost::property_tree::ptree &json_description)
{
    std::vector<char> alphabet;
    auto alphabet_list =  json_description.get_child("alphabet");
    for (auto &character : alphabet_list)
    {
        alphabet.emplace_back(character.second.get_value<char>());
    }
    return alphabet;
}
