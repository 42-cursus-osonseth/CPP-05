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
    std::string const name;
    const int signGrade;
    const int execGrade;
    bool _signed;
public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    ~AForm();

    const std::string &getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getSigned() const;
    void beSigned(Bureaucrat const &bureaucrat);
    class GradeTooHighException : public std::exception{
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        const char *what() const throw();
    };
    class alreadySignedException : public std::exception{
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif