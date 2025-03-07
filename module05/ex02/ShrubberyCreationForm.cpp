#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Form", 145, 137) {
	target = "tree";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Form", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
: AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = copy.target;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		this->target = other.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::getTarget() const {
	return(target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
	{
		throw NotSignedException();
	}
	if (this->getExecuteGrade() < executor.getGrade())
	{
		throw GradeTooLowException();
	}
	std::ofstream	outfile((this->target + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: File can't be created" << std::endl;
		return ;
	}

	outfile <<	"                                                  ." << std::endl;
	outfile <<	"                                   .         ;  " << std::endl;
	outfile <<	"      .              .              ;%     ;;   " << std::endl;
	outfile <<	"        ,           ,                :;%  %;   " << std::endl;
	outfile <<	"         :         ;                   :;%;'     .,   " << std::endl;
	outfile <<	",.        %;     %;            ;        %;'    ,;" << std::endl;
	outfile <<	"  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	outfile <<	"   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	outfile <<	"    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	outfile <<	"     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	outfile <<	"      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	outfile <<	"         `:%;.  :;bd%;          %;@%;'" << std::endl;
	outfile <<	"           `@%:.  :;%.         ;@@%;'   " << std::endl;
	outfile <<	"             `@%.  `;@%.      ;@@%;        "  << std::endl;
	outfile <<	"               `@%%. `@%%    ;@@%;        " << std::endl;
	outfile <<	"                 ;@%. :@%%  %@@%;       " << std::endl;
	outfile <<	"                   %@bd%%%bd%%:;     " << std::endl;
	outfile <<	"                     #@%%%%%:;;" << std::endl;
	outfile <<	"                     %@@%%%::;" << std::endl;
	outfile <<	"                     %@@@%(o);  . '         " << std::endl;
	outfile <<	"                     %@@@o%;:(.,'         " << std::endl;
	outfile <<	"                 `.. %@@@o%::;         " << std::endl;
	outfile <<	"                    `)@@@o%::;         " << std::endl;
	outfile <<	"                     %@@(o)::;        " << std::endl;
	outfile <<	"                    .%@@@@%::;         " << std::endl;
	outfile <<	"                    ;%@@@@%::;.          " << std::endl;
	outfile <<	"                   ;%@@@@%%:;;;. " << std::endl;
	outfile <<	"               ...;%@@@@@%%:;;;;,.." << std::endl;

	outfile.close();
}