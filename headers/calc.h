#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <ctime>
#include <vector>
#include "pik.h"
#include "temp.h"

class Calc
{
public:
    Calc();
    Calc(std::string pik, std::string temp);

    void get_temperature(std::string temp, int& error);
    void get_pik(std::string pik, int& error);

    std::vector<DataTemp> data_temp;
    std::vector<DataPik> data_pik;
};

#endif