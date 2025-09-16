#include <iostream>
#include <ctime>
#include "./headers/calc.h"

int main()
{
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";

    Calc calc(pik, temp);

    // for(int i = 0; i<calc.data_pik.size(); i++)
    //     std::cout<<calc.data_pik[i].date.tm_mday << "\n";

    return 0;
}