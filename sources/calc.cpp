#include "../headers/calc.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

Calc::Calc(){}

Calc::Calc(std::string pik, std::string temp)
{
    int temp_error {-1};
    get_temperature(temp, temp_error);
    
    int pik_error {-1};
    get_pik(pik, pik_error);
}

void Calc::get_temperature(std::string filename, int& error)
{
    std::ifstream file(filename);
    std::string line;

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        error = 1;
        return;
    }

    // Skip the first line (header)
    std::getline(file, line);

    // Read the rest of the lines
    while (std::getline(file, line)) 
    {
        std::istringstream lineStream(line);
        std::string dateStr, tempStr;

        // Split the line by comma
        std::getline(lineStream, dateStr, ',');
        std::getline(lineStream, tempStr);

        // Check for missing date
        if (dateStr.empty()) {
            std::cerr << "Missing date in line: " << line << std::endl;
            error = 2; // Set error code for missing date
            continue; // Skip this line
        }

        // Check for missing temperature
        if (tempStr.empty()) {
            std::cerr << "Missing temperature in line: " << line << std::endl;
            error = 3; // Set error code for missing temperature
            continue; // Skip this line
        }

        // Parse the date string into std::tm structure
        std::tm datetime = {};
        std::istringstream dateStream(dateStr);
        dateStream >> std::get_time(&datetime, "%Y-%m-%d %H:%M:%S");

        // Check if date parsing was successful
        if (dateStream.fail()) {
            std::cerr << "Wrong date format in line: " << line << std::endl;
            error = 4; // Set error code for wrong date format
            continue; // Skip this line
        }

        // Convert temperature to double and check for validity
        try {
            double temperature = std::stod(tempStr);
            DataTemp dt(datetime, temperature);

            // Store the data point
            data_temp.push_back(dt);
        } catch (const std::invalid_argument&) {
            std::cerr << "Wrong temperature format in line: " << line << std::endl;
            error = 5; // Set error code for wrong temperature format
            continue; // Skip this line
        } catch (const std::out_of_range&) {
            std::cerr << "Temperature out of range in line: " << line << std::endl;
            error = 6; // Set error code for temperature out of range
            continue; // Skip this line
        }
    }

    file.close(); // Close the file
}

void Calc::get_pik(std::string filename, int& error)
{
    std::ifstream file(filename);
    std::string line;

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        error = 1;
        return;
    }

    // Skip the first line (header)
    std::getline(file, line);

    // Read the rest of the lines
    while (std::getline(file, line)) 
    {
        std::istringstream lineStream(line);
        std::string dateStr, tempStr;

        // Split the line by comma
        std::getline(lineStream, dateStr, ',');
        std::getline(lineStream, tempStr);

        // Check for missing date
        if (dateStr.empty()) {
            std::cerr << "Missing date in line: " << line << std::endl;
            error = 2; // Set error code for missing date
            continue; // Skip this line
        }

        // Check for missing temperature
        if (tempStr.empty()) {
            std::cerr << "Missing pik in line: " << line << std::endl;
            error = 3; // Set error code for missing temperature
            continue; // Skip this line
        }

        // Parse the date string into std::tm structure
        std::tm datetime = {};
        std::istringstream dateStream(dateStr);
        dateStream >> std::get_time(&datetime, "%Y-%m-%d");

        // Check if date parsing was successful
        if (dateStream.fail()) {
            std::cerr << "Wrong date format in line: " << line << std::endl;
            error = 4; // Set error code for wrong date format
            continue; // Skip this line
        }

        // Convert pik to double and check for validity
        try {
            double pik = std::stod(tempStr);
            DataPik dt(datetime, pik);

            // Store the data point
            data_pik.push_back(dt);
        } catch (const std::invalid_argument&) {
            std::cerr << "Wrong pik format in line: " << line << std::endl;
            error = 5; // Set error code for wrong pik format
            continue; // Skip this line
        } catch (const std::out_of_range&) {
            std::cerr << "pik out of range in line: " << line << std::endl;
            error = 6; // Set error code for pik out of range
            continue; // Skip this line
        }
    }

    file.close(); // Close the file
}


