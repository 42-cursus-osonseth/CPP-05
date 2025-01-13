#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "shrubbery", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    action();
}

void ShrubberyCreationForm::action() const
{
    std::ofstream file;
    std::string fileName = getTarget() + "_shrubbery";
    file.open(fileName.c_str(), std::ios::out);
    if (!file)
    {
        std::cerr << "Error: Could not create file "<< fileName << std::endl;
        return;
    }
    file
        << "         ^" << std::endl
        << "        ^^^" << std::endl
        << "       ^^^^^" << std::endl
        << "      ^^^^^^^" << std::endl
        << "     ^^^^^^^^^" << std::endl
        << "    ^^^^^^^^^^^" << std::endl
        << "   ^^^^^^^^^^^^^" << std::endl
        << "       |||||" << std::endl
        << "       |||||" << std::endl
        << "       |||||" << std::endl;
    file.close();
}