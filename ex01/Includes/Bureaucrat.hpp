#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Colors.hpp"

class Form;
class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
    void signForm(Form &f);
    class GradeTooHighException : public std::exception{
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif