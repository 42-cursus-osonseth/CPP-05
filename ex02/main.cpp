#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
     
      
      Bureaucrat max ("Max", 4);
      AForm *a = new PresidentialPardonForm("BOOOUUUMM");
      max.signForm(*a);
      a->beSigned(max);
      std::cout << std::string(20, '-') << std::endl;
      max.signForm(*a);
      max.executeForm(*a);
      delete a;
      
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}