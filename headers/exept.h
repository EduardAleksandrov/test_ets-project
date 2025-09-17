#ifndef EXEPT_H
#define EXEPT_H
#include <iostream>

class Pexception: public std::exception
{
public: 
    Pexception(std::string message): message{message}{}
    std::string getMessage() const {return message;}
private:
    std::string message;
};

#endif