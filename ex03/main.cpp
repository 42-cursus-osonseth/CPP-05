#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

// int main()
// {

//   try
//   {
//     Bureaucrat max("Max", 0);
//     Bureaucrat tonton("tonton", 5);
//     AForm *a = new RobotomyRequestForm("test");
    

//     tonton.signForm(*a);
//     tonton.executeForm(*a);


//     delete a;
//   }
//   catch (const std::exception &e)
//   {
//     std::cerr << MAGENTA << e.what() << RESET << std::endl;
//   }

//   return 0;
// }

int main ()
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
    AForm *test3 = max.makeForm("TONTON", "shrubbery ");
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
