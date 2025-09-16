#ifndef TEMP_H
#define TEMP_H

#include <ctime>

struct DataTemp {
    std::tm datetime;
    double temperature;
};

#endif

    // std::tm datetime = {};
    // datetime.tm_year = 2025; // Year since 1900
    // datetime.tm_mon = 8; // September (0-11)
    // datetime.tm_mday = 16; // Day of the month
    // datetime.tm_hour = 12; // Hour (0-23)
    // datetime.tm_min = 30; // Minute (0-59)
    // datetime.tm_sec = 45; // Second (0-60)

    // std::cout << datetime.tm_hour+1;