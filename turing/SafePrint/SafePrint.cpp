#include "SafePrint.h"

void WriteString(const char *str, size_t len)
{
    std::cout.write(str, len);

    if (std::cout.exceptions() == std::ios_base::failbit)
    {
        std::cout << '\r';
        std::cout.write(str, len);
    }
}
