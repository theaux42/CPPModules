#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
    AForm("ShrubberyCreationForm", 137, 145), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
    AForm("ShrubberyCreationForm", 137, 145), _target(src.getTarget()) { *this = src; }

ShrubberyCreationForm::ShrubberyCreationForm(void) :
    AForm("ShrubberyCreationForm", 137, 145) , _target("default") {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) { (void)rhs; return *this; }

void ShrubberyCreationForm::action(const Bureaucrat &executor) const
{
    (void)executor;
    std::string filename = this->_target + "_shrubbery";
    std::ofstream TargetFile(filename.c_str());

    TargetFile << "       _-_\n";
    TargetFile << "    /~~   ~~\\\n";
    TargetFile << " /~~         ~~\\\n";
    TargetFile << "{               }\n";
    TargetFile << " \\  _-     -_  /\n";
    TargetFile << "   ~  \\ //  ~\n";
    TargetFile << "_- -   | | _- _\n";
    TargetFile << "  _ -  | |   -_\n";
    TargetFile << "      // \\\\" << std::endl;

    TargetFile.close();
}