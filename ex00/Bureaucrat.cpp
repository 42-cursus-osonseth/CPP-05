#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat:: Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade) {}
const std::string &Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::increaseGrade()
{
    grade--;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decreaseGrade()
{
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os
        << BLUE << b.getName() << RESET
        << YELLOW_ITALIC << ",  bureaucrat grade " << RESET
        << RED << b.getGrade() << RESET;
    return os;
}
