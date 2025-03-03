#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : signGrade(0), execGrade(0) {}
Form::~Form() {}
Form::Form(std::string n, int sG, int eG) : name(n), signGrade(sG), execGrade(eG), _signed(false)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}
Form:: Form(Form const &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), _signed(other._signed)
{

}

int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }
const std::string &Form::getName() const { return name; }
bool Form::getSigned() const { return _signed; }

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (_signed)
        throw Form::alreadySignedException();
    if (signGrade < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    std::string str;
    (f.getSigned()) ? str = "YES" : str = "NO";
    os
        << YELLOW_ITALIC << "Name       : " << RESET
        << GREEN << f.getName() << RESET << std::endl
        << YELLOW_ITALIC << "Exec grade : " << RESET
        << CYAN << f.getExecGrade() << RESET << std::endl
        << YELLOW_ITALIC << "Sign grade : " << RESET
        << CYAN << f.getSignGrade() << RESET << std::endl
        << YELLOW_ITALIC << "Signed     : " << RESET
        << RED << str << RESET;

    return os;
}