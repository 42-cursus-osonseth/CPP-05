#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        GradeTooHighException();
    if (grade > 150)
        GradeTooLowException();
}

std::string Bureaucrat::getName() const { return name; }
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
    throw std::runtime_error("The Grade is too HIGHT !");
}
void Bureaucrat::GradeTooLowException()
{
    throw std::runtime_error("The grade is too LOW");
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os
        << BLUE << b.getName() << RESET
        << YELLOW_ITALIC << ",  bureaucrat grade " << RESET
        << RED << b.getGrade() << RESET;
    return os;
}
