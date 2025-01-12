#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "Colors.hpp"


class Bureaucrat
{
private:
    std::string const name;
    int grade;
    void GradeTooHighException();
    void GradeTooLowException();

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    const std::string getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif