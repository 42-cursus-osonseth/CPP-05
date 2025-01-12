#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Max", 150);
        std::cout << a << std::endl;
        a.decreaseGrade();
        std::cout << a << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }

    return 0;
}