//
// Created by redone on 7/6/23.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
    AForm("Shrubbery Form", 145, 137),
    target(target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (this->getIsSigned() == false) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::ofstream file;
    std::string filename = target + "_shrubbery";
    file.open(filename.c_str());
    if (!file) {
        throw AForm::FileOpenException();
    }
    const std::string asciiTree =
            "             .     .  .      +     .      .          .\n"
            "     .       .      .     #       .           .\n"
            "        .      .         ###            .      .      .\n"
            "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
            "          .      . \"####\"###\"####\"  .\n"
            "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
            "  .             \"#########\"#########\"        .        .\n"
            "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
            "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
            "                .\"##\"#####\"#####\"##\"           .      .\n"
            "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
            "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
            "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
            "            .     \"      000      \"    .     .\n"
            "       .         .   .   000     .        .       .\n"
            ".. .. ..................O000O........................ ......\n";
    file << asciiTree;
    file.close();
}
