#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
      Form a ("test", 100, 134);
      Bureaucrat max ("Max", 101);
      a.beSigned(max);
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }

    return 0;
}