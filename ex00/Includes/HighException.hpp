#ifndef HIGH_EXCEPTION_HPP
#define HIGH_EXCEPTION_HPP

#include <exception>
#include <string>

class HighException : public std::exception
{
private:
    const std::string Error;

public:
    HighException() {}
    ~HighException() throw() {}
    HighException(std::string str) : Error(str + " grade is too high !") {}
    virtual const char *what() const throw();
};

#endif