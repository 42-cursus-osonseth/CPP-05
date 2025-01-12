#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
      Form a ("test", 0, 134);
      Bureaucrat max ("Max", 150);
      a.beSigned(max);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}