#pragma once

#include "SMachineDescription.h"

#include <string>
#include <iostream>

void InitTape(const std::string &input_data_for_tale, char blank);
void LeftHeadShift(char blank);
void RightHeadShift(char blank);
void RecordIntoTape(char chr);
char GetValueOfHead();
size_t GetPositionOfHead() noexcept(true);

void PrintStep(const std::string &current_state,
               char current_chr,
               const std::string &next_state,
               char next_chr,
               EAction next_action,
               size_t pos_for_mark);

void PrintTape();
