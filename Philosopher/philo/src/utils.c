/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:48:27 by seojo             #+#    #+#             */
/*   Updated: 2022/10/29 22:38:20 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_atolld(const char *str)
{
	const long long	max = LLONG_MAX;
	long long		num;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			return (ERROR);
	if (!(*str && '0' <= *str && *str <= '9'))
		return (ERROR);
	while (*str && *str >= '0' && *str <= '9')
	{
		if (num > max / 10 || (num == max / 10 && *str - '0' > max % 10))
			return (ERROR);
		num = num * 10 + *str++ - '0';
	}
	if (*str == '\0')
		return (num);
	return (ERROR);
}

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*buf;
	void	*ptr;
	int		i;

	i = cnt * size;
	buf = (void *)malloc(cnt * size);
	if (!buf)
		return (NULL);
	ptr = buf;
	while (i-- != 0)
		*(char *)buf++ = 0;
	return (ptr);
}

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	print_usage(int exit_code)
{
	printf("Wrong argument!\nusage: ./philo number_of_philos time_to_die"\
			" time_to_eat time_to_sleep [philo_must_eat]\n");
	return (exit_code);
}

int	print_error(char *msg)
{
	while (msg && *msg)
		write(1, msg++, 1);
	write(1, "\n", 1);
	return (1);
}
