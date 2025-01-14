#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
  Bureaucrat a("coplien", 100);
  Bureaucrat b = a;
  Form c("coplien", 50, 50);
  Form d = c;
  std::cout << b << std::endl<< std::string(30, '-') << std::endl << d << std::endl << std::endl;
  try
  {
    Form a("high sign", 0, 100);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }

  try
  {
    Form a("low sign", 151, 100);
    Bureaucrat tonton("tonton", 100);
    tonton.signForm(a);
    tonton.signForm(a);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
   try
  {
    Form a("high exec", 100, 0);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
   try
  {
    Form a("low exec", 100, 151);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
//-----------------------------------------------------------------------------------------------------------
  try
  {
    Form a("low exec", 100, 150);
    Bureaucrat tonton("tonton", 100);
    tonton.signForm(a);
    tonton.signForm(a);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }
  try
  {
    Form a("test", 100, 100);
    Bureaucrat tonton("tonton", 125);
    tonton.signForm(a);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }

  return 0;
}