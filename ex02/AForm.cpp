#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : signGrade(0), execGrade(0) {}
AForm::~AForm() {}
AForm::AForm(std::string n, int sG, int eG) : name(n), signGrade(sG), execGrade(eG), _signed(false)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}
AForm:: AForm(AForm const &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), _signed(other._signed)
{

}

int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }
const std::string &AForm::getName() const { return name; }
bool AForm::getSigned() const { return _signed; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (_signed)
        throw AForm::alreadySignedException();
    if (signGrade < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    _signed = true;
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