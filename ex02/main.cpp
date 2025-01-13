#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
  try
  {
    Bureaucrat max("Max", 100);
    Bureaucrat tonton("tonton", 5);
    AForm *a = new RobotomyRequestForm("test");
    

    tonton.signForm(*a);
    tonton.executeForm(*a);


    delete a;
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }

  return 0;
}
