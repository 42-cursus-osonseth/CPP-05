#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, "presidential", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other)
{

}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    action();
}

void PresidentialPardonForm::action() const
{

    std::cout << RED << getTarget() << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl << std::endl;
}
