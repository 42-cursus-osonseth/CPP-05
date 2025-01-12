#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "LowException.hpp"
#include "HighException.hpp"

AForm::AForm() : signGrade(0), execGrade(0) {}
AForm::~AForm() {}
AForm::AForm(std::string t, std::string n, int sG, int eG) : target(t), name(n), signGrade(sG), execGrade(eG), _signed(false)
{
    if (signGrade < 1 || execGrade < 1)
        GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        GradeTooLowException();
}
AForm::AForm(AForm const &other) : target(other.target), name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), _signed(other._signed)
{
}

int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }
const std::string &AForm::getName() const { return name; }
const std::string &AForm::getTarget() const { return target; }
bool AForm::getSigned() const { return _signed; }

void AForm::GradeTooHighException()
{
    throw HighException("Form :");
}
void AForm::GradeTooLowException()
{
    throw LowException("Form :");
}
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
    {
        bureaucrat.signForm(*this);
        GradeTooLowException();
    }
    _signed = true;
    bureaucrat.signForm(*this);
}
void AForm::execute(Bureaucrat const &executor) 
{
    if (executor.getGrade() > execGrade)
    {
        executor.executeForm(*this);
        GradeTooLowException();
    }
    executor.executeForm(*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
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