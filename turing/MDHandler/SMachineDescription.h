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
    bool operator < (struct STransition rhs) const
    {
        size_t hash_rhs = std::hash<char>{}(rhs.read)
                ^ std::hash<std::string>{}(rhs.to_state)
                ^ std::hash<char>{}(rhs.write)
                ^ std::hash<EAction>{}(rhs.action);

        size_t hash_lhs = std::hash<char>{}(this->read)
                          ^ std::hash<std::string>{}(this->to_state)
                          ^ std::hash<char>{}(this->write)
                          ^ std::hash<EAction>{}(this->action);

        return hash_lhs < hash_rhs;
    }

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
    std::map<std::string, std::set<struct STransition>> transitions;
};
