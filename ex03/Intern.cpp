#include "Intern.hpp"
// #include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    init_func_array();
    init_string_array();
}
Intern::~Intern() {}
Intern::Intern(Intern const &other)
{
    (void)other;
    init_func_array();
    init_string_array();
}
void Intern::init_string_array()
{
    nameForm[0] = "robotomy";
    nameForm[1] = "shrubbery";
    nameForm[2] = "presidential";
}
void Intern::init_func_array()
{
    func_ptr[0] = &Intern::createRobotomyForm;
    func_ptr[1] = &Intern::createShrubberyForm;
    func_ptr[2] = &Intern::createPresidentialForm;
}

AForm *Intern::makeForm(std::string target, std::string name) const
{
    try
    {
        int i = 0;
        while (i < 3 && nameForm[i] != name)
            i++;
        if (i == 3)
            throw Intern::wrongFormNameException();
        return (this->*func_ptr[i])(target);
    }
    catch (std::exception &e)
    {
        std::cout << MAGENTA << e.what() << RESET << std::endl
                  << std::endl;
        return NULL;
    }
}

AForm *Intern::createRobotomyForm(std::string target) const
{
    AForm *f = new RobotomyRequestForm(target);
    return f;
}
AForm *Intern::createShrubberyForm(std::string target) const
{
    AForm *f = new ShrubberyCreationForm(target);
    return f;
}
AForm *Intern::createPresidentialForm(std::string target) const
{
    AForm *f = new PresidentialPardonForm(target);
    return f;
}