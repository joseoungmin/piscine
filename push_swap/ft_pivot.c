/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:18:01 by seojo             #+#    #+#             */
/*   Updated: 2022/10/03 10:03:16 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_arr_to_arr(int *arr, int *n_arr, int *idx, int end)
{
	while (idx[0] <= end)
		n_arr[idx[3]++] = arr[idx[0]++];
}

static int	*ft_int_malloc(int end)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * end);
	if (!arr)
		ft_error(1);
	return (arr);
}

static void	merge(int *arr, int start, int mid, int end)
{
	int	idx[4];
	int	*n_arr;

	n_arr = ft_int_malloc(end + 1);
	idx[1] = start;
	idx[2] = mid + 1;
	idx[3] = start--;
	while (idx[1] <= mid && idx[2] <= end)
	{
		if (arr[idx[1]] <= arr[idx[2]])
			n_arr[idx[3]++] = arr[idx[1]++];
		else
			n_arr[idx[3]++] = arr[idx[2]++];
	}
	idx[0] = idx[2];
	if (idx[1] > mid)
		ft_arr_to_arr(arr, n_arr, idx, end);
	else
	{
		idx[0] = idx[1];
		ft_arr_to_arr(arr, n_arr, idx, mid);
	}
	while (++start <= end)
		arr[start] = n_arr[start];
}

static void	merge_sort(int *arr, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

void	ft_pivot_point(t_deque *stack, int *pivot_one, int *pivot_two, int len)
{
	const int	sort_len = len;
	int			*sort_num;
	int			i;
	t_node		*tmp;

	sort_num = (int *)malloc(sizeof(int) * len);
	if (!sort_num)
		ft_error(1);
	i = 0;
	tmp = stack->top;
	if (!tmp)
		ft_error(1);
	while (len--)
	{
		sort_num[i++] = tmp->num;
		tmp = tmp->next;
	}
	merge_sort(sort_num, 0, sort_len - 1);
	*pivot_one = sort_num[sort_len / 3];
	*pivot_two = sort_num[sort_len * 2 / 3];
	free(sort_num);
	sort_num = NULL;
}
