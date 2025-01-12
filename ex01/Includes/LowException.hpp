#ifndef LOW_EXCEPTION_HPP
#define LOW_EXCEPTION_HPP

#include <exception>
#include <string>

class LowException : public std::exception
{
private:
    const std::string Error;

public:
    LowException() {}
    ~LowException() throw() {}
    LowException(std::string str) : Error( YELLOW + str + RESET + RED " grade is too low !" + RESET) {}
    virtual const char *what() const throw();
};

#endif