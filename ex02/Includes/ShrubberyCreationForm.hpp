#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
    void action() const;
};

#endif