#ifndef PIK_H
#define PIK_H

#include <ctime>

struct DataPik {
    std::tm date;
    double pik;
    DataPik(std::tm d, double t): date{d}, pik(t){}
};

#endif