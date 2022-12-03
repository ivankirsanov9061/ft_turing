#pragma once

#include <iostream>

void Write(const char *str, size_t len);

template <typename T>
void Write(T &&value)
{
    std::cout << value;

    if (std::cout.exceptions() == std::ios_base::failbit)
    {
        std::cout << '\r';
        std::cout << value;
    }
}

template <typename ...T>
void Write(T &&...value)
{
    (Write(value), ...);
}

class SafePrint
{
public:
    void write(const char *str, size_t len);

    template <typename T>
    SafePrint &operator << (T &&value)
    {
        std::cout << value;

        if (std::cout.exceptions() == std::ios_base::failbit)
        {
            std::cout << '\r';
            std::cout << value;
        }
        return *this;
    }
};

extern SafePrint safe_cout;


