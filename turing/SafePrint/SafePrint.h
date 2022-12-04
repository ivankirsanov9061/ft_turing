#pragma once

#include <iostream>

void WriteString(const char *str, size_t len);

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
