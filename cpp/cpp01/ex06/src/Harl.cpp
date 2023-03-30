#include "Harl.hpp"

Harl::Harl() {
	f_complain[0] = &Harl::debug;
	f_complain[1] = &Harl::info;
	f_complain[2] = &Harl::warning;
	f_complain[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::debug(void){
	std::cout << "[ DEBUG ]\nI love having extra bacom for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info(void){
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void	Harl::warning(void){
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void){
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now." << std::endl;
}

void	Harl::nothing(void){
	std::cout << "[ Probably complaing insignificant problems ]" << std::endl; 
}

static int	getLevel(std::string level){
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool		found = false;
	int			i = 0;

	while (i < 5 & found == false)
		found = (level == levels[i++]);
	return (i - 1);
}

void    Harl::complain(std::string level) {
	int		complain = getLevel(level);
	
	switch (complain){
	 	case DEBUG:
	 		debug();
	 	case INFO:
	 		info();
	 	case WARNING:
	 		warning();
	 	case ERROR:
	 		error();
			break ;
		default:
			std::cout << "Invalid complain\n";
	 }
}
