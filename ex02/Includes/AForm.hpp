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
    std::string target;
    std::string const name;
    const int signGrade;
    const int execGrade;
    bool _signed;

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
    virtual void execute(Bureaucrat const &executor) const;
    virtual void action() const = 0;
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
    class alreadySignedException : public std::exception
    {
        const char *what() const throw();
    };
    class notSignedException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif