#pragma once

#include <string>
#include <iostream>

void InitTape(const std::string &input_data_for_tale);
void LeftHeadShift(char blank);
void RightHeadShift(char blank);
void RecordIntoTape(char chr);
char GetValueOfHead();

void PrintTape();
