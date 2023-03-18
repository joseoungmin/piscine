#include <iostream>

int	ft_islower(char c)
{
	return ('a' <= c && c <= 'z');
}

void	print_str_toupper(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if (ft_islower(str[i]) == true)
			str[i] = toupper(str[i]);
		i++;
	}
	std::cout << str;
}

int main(int ac, char **av)
{
	int i = 1;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		while (av[i])
			print_str_toupper(av[i++]);
	}
	std::cout << std::endl;
	return (0);
}
