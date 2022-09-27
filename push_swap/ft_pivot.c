/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojo <seojo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:18:01 by seojo             #+#    #+#             */
/*   Updated: 2022/09/27 20:27:41 by seojo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(int *arr, int start, int end)
{
	int	mid;
    if (start < end)
    {
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start, mid, end);
    }
}

void	merge(int *arr, int start, int mid, int end)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
		if (arr[i] <= arr[j])
	    	n_arr[k++] = arr[i++];
		else
	    	n_arr[k++] = arr[j++];
    }
    if (i > mid)
	for (int t=j; t<=end; t++)
	    n_arr[k++] = arr[t];
    else
		for (int t=i; t<=mid; t++)
	    	n_arr[k++] = arr[t];
    for(int t=start; t<=end; t++)
	arr[t] = n_arr[t];
}

int	ft_pivot_point(t_total *total, int *pivot_one, int *pivot_two)
{
	int		*sort_num;
	t_node	tmp;

	sort_num = (int *)malloc(sizeof(int) * total->a->size);
	if (!sort_num)
		ft_error(1);
	tmp//첫노드 담고, 반복문으로 배열에 담아주고, 정렬된거 2/3  1/3 번째 찾아서 피벗으로 잡는다;
	   //pivot one pivot two
	   //size * 2/3 size * 1/3
	
	merge_sort(sort_num, 0, n-1);
	free(sort_num);
}
