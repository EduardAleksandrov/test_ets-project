#include <iostream>
#include <ctime>
#include "./headers/calc.h"

int main()
{
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";

    Calc c(pik,temp);

    return 0;
}