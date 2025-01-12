#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Max", 150);
        Bureaucrat b = a;
        std::cout << a << std::endl;
      
        std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }

    return 0;
}