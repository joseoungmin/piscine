/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/09/21 15:33:59 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//top 에 넣고빼고
//bottom 에 넣고빼고

//노드 하나씩 돌리고 
//노드의 넥스트는 노드

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
t_dlst	*ft_lstlast(t_dlst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_dlst	*ft_lstnew(int content)
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

void	ft_lstadd_next(t_dlst **deque, t_dlst *new)
{
	if (!deque || !new)
		return ;
	if (!*deque)
		*deque = new;
	else
	{
		(*deque)->a->bottom->next = new;
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
    t_dlst   a_deque;
/*큰거 만들고 함수에 보내줄때 작은거 보내주기 파싱용 함수 분리하기
	t_total	deque;

	deque.a = (t_deque *)malloc(sizeof(t_deque));
	parsing(deque.a, av);	

t_total->t_deque->t_dlst
(*t_total).(*t_deque).t_dlst
	void	ft_error(void)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
*/
	a_deque = NULL;
	a_deque.size = 0;
    if (ac == 1)
        return (0);
    i = 0;
    while(av[++i])
    {
        j = -1;
        buf = ft_split(av[i], ' ');
		if (!buf)
			ft_error(1);//	디버깅을 위한 exit number
		if (buf && !*buf)
			ft_error(2);
        while (buf[++j])
        {
            k = -1;
			atoint = ft_atoi(buf[j]);
			if (!ft_check_num(buf[j]) || ft_check_dup(deque, atoint))
				return (rt_error());
        	ft_lstadd_next(&deque, ft_lstnew(atoint));
        }
		a_deque.size += j;
		free_dptr(buf);
    }

	printf("a_stack\n");
    while (deque)
    {
        printf("%d\n", deque->num);
        deque = deque->next;
    }
	printf("a_deque.size = %d\n", a_deque.size);
}
