#pragma once

#include <string>

struct SMachineDescription ParseAndValidateMD(std::string &json_file_path, std::string &input_data_for_tape);
