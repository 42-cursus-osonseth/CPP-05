#ifndef HIGH_EXCEPTION_HPP
#define HIGH_EXCEPTION_HPP

#include <exception>
#include <string>
#include "Colors.hpp"

class HighException : public std::exception
{
private:
    const std::string Error;

public:
    HighException() {}
    ~HighException() throw() {}
    HighException(std::string str) : Error( YELLOW + str + RESET + RED " grade is too high !" + RESET) {}
    const char *what() const throw();
};

#endif