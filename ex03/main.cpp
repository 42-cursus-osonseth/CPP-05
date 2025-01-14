#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
  try
  {
    Intern max;
    AForm *test = max.makeForm("TRENT", "robotomy");
    AForm *test1 = max.makeForm("MAX", "presidential");
    AForm *test2 = max.makeForm("TONTON", "shrubbery");
    std::cout << *test << std::endl;
    std::cout << *test1 << std::endl;
    std::cout << *test2 << std::endl;
    AForm *test3 = max.makeForm("TONTON", "Wrong name");
    Bureaucrat b("tonton", 1);
    b.signForm(*test);
    b.signForm(*test1);
    b.signForm(*test2);
    b.executeForm(*test);
    b.executeForm(*test1);
    b.executeForm(*test2);
    delete test;
    delete test1;
    delete test2;
    delete test3;
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
}
