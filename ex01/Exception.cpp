#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat has too low grade ... !");
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat has too hight grade ... !");
}
const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form has too low grade ... !");
}
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form has too hight grade ... !");
}

