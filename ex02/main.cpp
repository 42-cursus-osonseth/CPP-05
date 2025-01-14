#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

  {
    PresidentialPardonForm a("max");
    RobotomyRequestForm b("trent");
    ShrubberyCreationForm c("boum");

    PresidentialPardonForm d = a;
    RobotomyRequestForm e = b;
    ShrubberyCreationForm f = c;

    std::cout
        << d << std::endl
        << e << std::endl
        << f << std::endl
        << std::string(30, '-') << std::endl;
  }
  try
  {
    Bureaucrat tonton("tonton", 1);
    AForm *a = new PresidentialPardonForm("TARGET");
    tonton.executeForm(*a);
    delete a;
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
   try
  {
    Bureaucrat tonton("tonton", 145);
    AForm *a = new ShrubberyCreationForm("TARGET");
    tonton.signForm(*a);
    tonton.executeForm(*a);
    delete a;
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
  try
  {
    Bureaucrat tonton("tonton", 1);
    AForm *a = new PresidentialPardonForm("TARGET");
    AForm *b = new RobotomyRequestForm("TARGET");
    AForm *c = new ShrubberyCreationForm("TARGET");
    tonton.signForm(*a);
    tonton.signForm(*b);
    tonton.signForm(*c);
    tonton.executeForm(*a);
    tonton.executeForm(*b);
    tonton.executeForm(*c);
    delete a;
    delete b;
    delete c;
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }

  return 0;
}
