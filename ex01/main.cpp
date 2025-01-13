#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
      Form a ("test", 100, 134);
      Form b = a;
      Bureaucrat max ("Max", 101);
      a.beSigned(max);
      std::cout << std::string(20, '-') << std::endl;
      std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() <<  RESET << std::endl;
    }

    return 0;
}