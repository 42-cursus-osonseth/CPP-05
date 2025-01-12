#include "Bureaucrat.hpp"
#include "LowException.hpp"
#include "HighException.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        GradeTooHighException();
    if (grade > 150)
        GradeTooLowException();
}
Bureaucrat:: Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{

}

const std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }
void Bureaucrat::increaseGrade()
{
    grade--;
    if (grade < 1)
        GradeTooHighException();
}
void Bureaucrat::decreaseGrade()
{
    grade++;
    if (grade > 150)
        GradeTooLowException();
}
void Bureaucrat::GradeTooHighException()
{
    throw HighException("Bureaucrat:");
}
void Bureaucrat::GradeTooLowException()
{
    throw LowException("Bureaucrat:");
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os
        << BLUE << b.getName() << RESET
        << YELLOW_ITALIC << ",  bureaucrat grade " << RESET
        << RED << b.getGrade() << RESET;
    return os;
}
