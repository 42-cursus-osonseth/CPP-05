#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
  try
  {
    Bureaucrat max("Max", 100);
    Bureaucrat tonton("tonton", 5);
    AForm *a = new PresidentialPardonForm("test");
    AForm *b = new ShrubberyCreationForm("tree");

    tonton.signForm(*a);
    tonton.executeForm(*a);
    tonton.signForm(*b);
    tonton.executeForm(*b);

    delete a;
    delete b;
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }

  return 0;
}
