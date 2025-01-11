#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() {}
Form::~Form() {}
Form::Form(std::string n, int sG, int eG) : name(n), signGrade(sG), execGrade(eG), _signed(false)
{
    if (signGrade < 1 || execGrade < 1)
        GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        GradeTooLowException();
}

int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }
const std::string &Form::getName() const { return name; }
bool Form::getSigned() const { return _signed; }

void Form::GradeTooHighException()
{
    throw std::runtime_error("The Grade is too HIGHT !");
}
void Form::GradeTooLowException()
{
    throw std::runtime_error("The grade is too LOW");
}
void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
    {
        bureaucrat.signForm(*this);
        GradeTooLowException();
    }
    _signed = true;
    bureaucrat.signForm(*this);
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