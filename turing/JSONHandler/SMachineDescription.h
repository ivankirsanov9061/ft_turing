#pragma once

#include <string>
#include <set>
#include <map>

enum EAction
{
    RIGHT,
    LEFT
};

struct STransition
{
    char read;
    std::string to_state;
    char write;
    EAction action;
};

struct SMachineDescription
{
    std::string name;
    char blank;
    std::string initial;
    std::set<std::string> finals;
    std::map<std::string, struct STransition> transitions;
};
