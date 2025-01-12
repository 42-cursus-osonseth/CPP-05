#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Colors.hpp"

class Bureaucrat;
class AForm
{
private:

    std::string const target;
    std::string const name;
    const int signGrade;
    const int execGrade;
    bool _signed;
    void GradeTooHighException();
    void GradeTooLowException();

public:
    AForm();
    AForm(std::string target, std::string name, int signGrade, int execGrade);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();

    const std::string &getName() const;
    const std::string &getTarget() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getSigned() const;
    void beSigned(Bureaucrat const &bureaucrat);
    void execute(Bureaucrat const &executor);
    virtual void action () const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif