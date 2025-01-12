#include "Bureaucrat.hpp"
#include "AForm.hpp"
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
    throw HighException("Bureaucrat :");
}
void Bureaucrat::GradeTooLowException()
{
    throw LowException("Bureaucrat :");
}
void Bureaucrat::signForm(AForm const &f) const
{
    if (f.getSigned())
    {
        std::cout
            << BLUE << name << RESET
            << GREEN "      signed " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << f << std::endl;
    }
    else if (!f.getSigned())
    {
        std::cout
            << RED " Form is not signed ! " << RESET << std::endl;

    }
    else
    {
          std::cout
            << BLUE << name << RESET
            << RED " couldn't sign : " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << f << std::endl
            << RED "because " << RESET
            << BLUE << name << RESET
            << RED " has a grade sign too low !" << RESET << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const & form) const
{
    if (grade <= form.getExecGrade() && form.getSigned())
    {
        std::cout
            << BLUE << name << RESET
            << GREEN "      executed " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << form << std::endl;
        form.action();
    }
    else if (!form.getSigned())
    {
        std::cout
            << BLUE << name << RESET
            << RED " couldn't execute : " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << form << std::endl
            << RED "because the form is not signed !" << RESET << std::endl;
    }
    else
    {
         std::cout
            << BLUE << name << RESET
            << RED " couldn't execute : " << RESET << std::endl
            << YELLOW << std::string(18, '-') << RESET << std::endl
            << form << std::endl
            << RED << "because " << RESET
            << BLUE << name << RESET
            << RED " has a grade to execute too low !" << RESET << std::endl;
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
