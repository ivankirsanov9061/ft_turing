#include "SafeStreamWriter.h"

void SafeStreamWrite(std::ostream &stream, std::string information)
{
    stream.write(information.c_str(), information.size());

    if (stream.exceptions() == std::ios_base::failbit)
    {
        stream.write(('\r' + information).c_str(), information.size() + 1);
    }
}
