#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat has too low grade... !");
}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat has too hight grade... !");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Form has too low grade... !");
}
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Form has too hight grade... !");
}
const char *AForm::alreadySignedException::what() const throw()
{
    return ("Form is already signed... !");
}
const char *AForm::notSignedException::what() const throw()
{
    return ("Form is not signed... !");
}
const char *Intern::wrongFormNameException::what() const throw()
{
    return ("internal can't create the form because the form name does not exist... !");
}