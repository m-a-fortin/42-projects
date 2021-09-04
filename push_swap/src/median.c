/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:58:52 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/01 14:52:47 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//copie un stack vers cpy
void	ft_copy_stack(t_stack *stack, t_stack *cpy)
{
	int	size_temp;

	size_temp = stack->size;
	while (size_temp > 0)
	{
		cpy->value[size_temp] = stack->value[size_temp];
		size_temp--;
	}
	cpy->size = stack->size;
}

//Quick_Sort Loop
int	ft_partition(t_stack *stack, int low, int high, int pivot)
{
	int	i;
	int	j;

	i = low - 1;
	j = low;
	while (j < high)
	{
		if (stack->value[j] < pivot)
		{
			i++;
			swap(stack, i, j);
		}
		j++;
	}
	swap(stack, i + 1, high);
	return (i + 1);
}

//Sort un stack(cpy) afin de trouver la median
void	ft_quick_sort(t_stack *stack, int low, int high)
{
	int	index;
	int	pivot;

	pivot = stack->value[high];
	index = 0;
	if (low < high)
	{
		index = ft_partition(stack, low, high, pivot);
		ft_quick_sort(stack, low, index - 1);
		ft_quick_sort(stack, index + 1, high);
	}
}

void	ft_rank(t_stack *stack, t_stack *cpy)
{
	int	size;
	int	i;

	i = cpy->size;
	size = stack->size;
	while (size > 0)
	{
		i = cpy->size;
		while (i > 0)
		{
			if (stack->value[size] == cpy->value[i])
			{
				stack->value[size] = i;
				cpy->value[i] = LONG_MAX;
				break ;
			}
			else
				i--;
		}
		size--;
	}
}

//Trouver la median.
void	ft_find_median(t_stack *stack, t_stack *cpy, t_stats *stats)
{
	t_stack	*test;

	test = malloc(sizeof(t_stack) * 1);
	if (!cpy)
	{
		stats->error = 1;
		return ;
	}
	cpy->value = ft_calloc(stack->size, sizeof(long) + 1);
	test->value = ft_calloc(stack->size, sizeof(long) + 1);
	ft_copy_stack(stack, cpy);
	ft_copy_stack(stack, test);
	ft_quick_sort(cpy, 1, cpy->size);
	ft_rank(stack, cpy);
}
