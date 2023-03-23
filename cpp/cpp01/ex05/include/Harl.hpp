#ifndef	HARL_HPP
#define	HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	private:
		void	(Harl::*f_complain[4])(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level);

		Harl();
		~Harl();
};

#endif