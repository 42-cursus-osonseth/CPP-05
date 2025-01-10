#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Max", 1);
        std::cout << a << std::endl;
        a.increaseGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << MAGENTA << e.what() << RESET << std::endl;
    }

    return 0;
}