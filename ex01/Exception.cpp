#include "HighException.hpp"
#include "LowException.hpp"

const char *LowException::what() const throw()
{
    return Error.c_str();
}
const char *HighException::what() const throw()
{
    return Error.c_str();
}