#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, "presidential", 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) 
{
   Form::execute(executor);
   action();
}

void PresidentialPardonForm::action () const
{

    std::cout << RED << getTarget() <<  " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
