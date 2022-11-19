#include "SafeStreamWriter.h"

void SafeStreamWrite(std::ostream &output_stream_for_information, const std::string &&information)
{
    output_stream_for_information.write(information.c_str(), information.size());

    if (output_stream_for_information.exceptions() == std::ios_base::failbit)
    {
        output_stream_for_information.write(('\r' + information).c_str(), information.size() + 1);
    }
}
