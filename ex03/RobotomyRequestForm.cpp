#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, "robotomy", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const &other) : AForm(other)
{

}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    action();
}

void RobotomyRequestForm::action() const
{
    std::srand(std::time(0));
    int random_number = std::rand() % 100 + 1;
    std::cout << RED << "Bzzzzt... Bzzzzt... Brrrrrzzzttt!" << RESET << std::endl;
    if (random_number % 2 == 0)
        std::cout << RED << getTarget() << ": has been robotomized successfully " << RESET << std::endl << std::endl;
    else
        std::cout << RED << "Robotomization failed" << RESET << std::endl << std::endl;
}