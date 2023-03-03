/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:16:55 by seojo             #+#    #+#             */
/*   Updated: 2023/03/03 19:59:12 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_islower(char c)
{
	return ('a' <= c && c <= 'z');
}

void	print_str_toupper(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (ft_islower(str[i]))
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
		{
			print_str_toupper(av[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
