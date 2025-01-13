#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Colors.hpp"

class Bureaucrat;
class Form
{
private:
    std::string const name;
    const int signGrade;
    const int execGrade;
    bool _signed;
public:
    Form();
    Form(std::string name, int signGrade, int execGrade);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();

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
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif