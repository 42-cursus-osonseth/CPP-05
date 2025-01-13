#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat has too low grade ... !");
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat has too hight grade ... !");
}

