#pragma once

#include <string>
#include <vector>

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
    std::vector<std::string> finals;
    std::vector<std::pair<std::string, std::vector<struct STransition>>> transitions;
};
