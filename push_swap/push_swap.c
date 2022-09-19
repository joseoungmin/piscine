/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:13:49 by seojo             #+#    #+#             */
/*   Updated: 2022/09/19 20:34:55 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	s;

	s = 0;
	while (src[s])
		s++;
	if (size)
	{
		while (*src && --size)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (s);
}

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

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	i;

	buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buf)
		return (NULL);
	i = -1;
	while (s[++i])
		buf[i] = s[i];
	buf[i] = '\0';
	return (buf);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	if ((size_t)start >= i)
		return (ft_strdup(""));
	i -= start;
	if (i > len)
		i = len;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, i + 1);
	return (str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s)
	{
		if (*s != c && (*(s + 1) == '\0' || *(s + 1) == c))
			cnt++;
		s++;
	}
	return (cnt);
}

static char	**ft_free_dptr(char	**s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		words_idx;
	char	*word_tmp;
	char	**buf;

	buf = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !buf)
		return (NULL);
	words_idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_tmp = (char *)s;
			while (*s && *s != c)
				s++;
			buf[words_idx] = ft_substr(word_tmp, 0, s - word_tmp);
			if (!buf[words_idx++])
				return (ft_free_dptr(buf, words_idx - 1));
		}
	}
	buf[words_idx] = NULL;
	return (buf);
}

typedef struct s_lst
{
    int     num;
    struct s_lst *perv;
    struct s_lst *next;
}   t_lst;

t_lst	*ft_lstlast(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_lstnew(int content)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
    new->perv = NULL;
	return (new);
}

void	ft_lstadd_next(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
        new->perv = last;
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

int	ft_check_dup(t_lst *head, int num)
{
	t_lst *point;

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
    t_lst   *deque;
	int		a_count;

	deque = NULL;
	a_count = 0;
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
        	ft_lstadd_next(&deque, ft_lstnew(atoint));
        }
		a_count += j;
		free_dptr(buf);
    }
	printf("a_stack\n");
    while (deque)
    {
        printf("%d\n", deque->num);
        deque = deque->next;
    }
	printf("a_count = %d\n", a_count);
}
