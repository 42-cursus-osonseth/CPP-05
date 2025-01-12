#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
     
      
      Bureaucrat max ("Max", 4);
      PresidentialPardonForm a("BOOM");
      max.signForm(a);
      a.beSigned(max);
      std::cout << std::string(20, '-') << std::endl;
      max.signForm(a);
      max.executeForm(a);
      
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}