#include "../push_swap.h"
#include <stdio.h>
	
int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (num * sign > 2147483647 || -2147483648 > num * sign)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return ((int)num * sign);
}

//t_deque->bottom 으로 변경

t_dlst	*ft_dlstnew(int content)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
    new->perv = NULL;
	return (new);
}

void	ft_lstadd_next(t_total *deque, t_dlst *new)
{
	if (!&deque || !new)
		return ;
	if (!deque)
		deque->a->top = new;
	else
	{
		deque->a->bottom->next = new;
        new->perv = (*deque)->a->bottom;
		(*deque)->a->bottom = new;
	}
}

int	ft_check_num(char *str)
{
	while(*str == '-' || *str == '+')
	{
		if (*(str + 1) == '-' || *(str + 1) == '+')
			return (0);
		str++;
	}
	while('0' <= *str && *str <= '9')
		str++;
	if (!*str)
		return (1);
	return (0);
}

int	ft_check_dup(t_dlst *head, int num)
{
	t_dlst *point;

	point = head;
	while (point)
	{
		if (point->num == num)
			return (1);
		point = point->next;
	}
	return (0);
}

void	free_dptr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

int main(int ac, char **av)
{
    int     i;
    int     j;
    int     k;
	int		atoint;
    char    **buf;
    t_total   deque;

	deque.a = NULL;
	deque.a.size = 0;
    if (ac == 1)
        return (0);
    i = 0;
    while(av[++i])
    {
        j = -1;
        buf = ft_split(av[i], ' ');
        while (buf[++j])
        {
            k = -1;
			atoint = ft_atoi(buf[j]);
			if (!ft_check_num(buf[j]) || ft_check_dup(deque, atoint))
				return (write(1, "Error\n", 6));
        	ft_lstadd_next(&deque, ft_dlstnew(atoint));
        }
		deque.a.size += j;
		free_dptr(buf);
    }
	printf("a_stack\n");
    while (deque)
    {
        printf("%d\n", deque.a->num);
        deque.a->top = deque.a->next;
    }
	printf("a_count = %d\n", deque.a.size);
}
