#pragma once

#include <string>

struct SMachineDescription ParseAndValidateMD(const std::string &json_file_path, const std::string &input_data_for_tape);
