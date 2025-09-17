#include <iostream>
#include <ctime>
#include "./headers/calc.h"

int main()
{
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";

    Calc calc(pik, temp);

    try
    {
        bool result = calc.check_pik_time("2017-01-11 18:00:00.000");
        std::cout << result << std::endl;
    }
    catch (const Pexception& err)
    {
        std::cout << "Date error: " << err.getMessage() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Something wrong"<< std::endl;
    }


    // for(int i = 0; i<calc.data_pik.size(); i++)
    //     std::cout<<calc.data_pik[i].date.tm_mday << "\n";

    return 0;
}