#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
  try
  {
    Form a("test", 100, 100);

    Bureaucrat max("Max", 101);
    Bureaucrat tonton("tonton", 100);
    max.signForm(a);
    tonton.signForm(a);
    tonton.signForm(a);
  }
  catch (const std::exception &e)
  {
    std::cerr << MAGENTA << e.what() << RESET << std::endl;
  }

  return 0;
}