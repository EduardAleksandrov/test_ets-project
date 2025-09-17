#include <iostream>
#include <ctime>
#include "./headers/calc.h"

using namespace std;

int main()
{
    std::string pik = "./task/mo_pik.csv";
    std::string temp = "./task/mo_temp.csv";

    Calc calc(pik, temp);

    std::cout << std::endl;

    try
    {
        // Вводим дату
        std::string time{"2017-01-11 18:00:00.000"};
        bool result = calc.check_pik_time(time);

        std::string result_cout;
        if(result == 1) result_cout = "Верно";
        else result_cout = "Неверно";

        std::cout << "Проверка пикового времени: " << result_cout << std::endl;
    }
    catch (const Pexception& err)
    {
        std::cout << "Date error: " << err.getMessage() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Something wrong"<< std::endl;
    }

    try
    {
        // Вводим температуру
        double temperature_predict {10};
        int predict_hour = calc.predict_peak_hour(temperature_predict);
        cout << "Прогноз часа нагрузки: " << predict_hour << endl;
    }
    catch (const Pexception& err)
    {
        std::cout << "Pridiction error: " << err.getMessage() << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Something wrong"<< std::endl;
    }

    // for(int i = 0; i<calc.data_pik.size(); i++)
    //     std::cout<<calc.data_pik[i].date.tm_mday << "\n";

    return 0;
}