#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Max",69 );
        Bureaucrat b = a;
        std::cout << b << std::endl;
       
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }
     try
    {
        Bureaucrat a("Max", 0);
        std::cout << a << std::endl;
       
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }
     try
    {
        Bureaucrat a("Max", 151);
        std::cout << a << std::endl;
       
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }

    return 0;
}