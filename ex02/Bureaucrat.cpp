#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
}

std::string Bureaucrat::getName() const { return name; }
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

void Bureaucrat::signForm(AForm &f)
{

    try
    {
        f.beSigned(*this);
        std::cout
            << BLUE << name << RESET
            << GREEN << "      signed " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << f << std::endl << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout
            << BLUE << name << RESET
            << RED << " couldn't sign " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << f << std::endl
            << RED << "because " << RESET
            << MAGENTA << e.what() << RESET << std::endl << std::endl;
    }
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os
        << BLUE << b.getName() << RESET
        << YELLOW_ITALIC << ",  bureaucrat grade " << RESET
        << RED << b.getGrade() << RESET;
    return os;
}
