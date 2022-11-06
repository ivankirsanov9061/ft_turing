#pragma once

#include "SArguments.h"

struct SArguments ParseArguments(int argc, const char * const *argv, std::ostream &output_stream_for_information);
