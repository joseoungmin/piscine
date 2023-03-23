#include "Harl.hpp"

Harl::Harl() {
	f_complain[0] = &Harl::debug;
	f_complain[1] = &Harl::info;
	f_complain[2] = &Harl::warning;
	f_complain[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::debug(void){
	std::cout << "I love having extra bacom for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level) {
	if (level == "DEBUG")
		(this->*f_complain[0])();
	else if (level == "INFO")
		(this->*f_complain[1])();
	else if (level == "WARNING")
		(this->*f_complain[2])();
	else if (level == "ERROR")
		(this->*f_complain[3])();
}
