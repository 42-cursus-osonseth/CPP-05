#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor);
    void action () const;
};

#endif