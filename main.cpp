#include <iostream>
#include <ctime>
#include "./headers/calc.h"

int main()
{
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";

    Calc calc(pik, temp);

    // for(int i = 0; i<calc.data_temp.size(); i++)
    //     std::cout<<calc.data_temp[i].datetime.tm_hour << "\n";

    return 0;
}