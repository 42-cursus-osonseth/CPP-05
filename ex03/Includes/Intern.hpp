#ifndef INTERN_HPP
#define INTERNE_HPP

#include <string>

class AForm;
class Intern
{
private:
    AForm *(Intern::*func_ptr[3])(std::string target) const;
    std::string nameForm[3];
    void init_string_array();
    void init_func_array();

public:
    Intern();
    Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();
    AForm *createRobotomyForm(std::string target) const;
    AForm *createShrubberyForm(std::string target) const;
    AForm *createPresidentialForm(std::string target) const;
    AForm *makeForm(std::string target, std::string name) const;
    class wrongFormNameException : public std::exception{
        const char *what() const throw();
    };
};

#endif