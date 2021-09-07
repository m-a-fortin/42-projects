/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:48:08 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/07 10:39:19 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_lowest_number(t_stack *stack)
{
	int	low;
	int	size_temp;

	size_temp = stack->size;
	low = INT_MAX;
	while (size_temp > 0)
	{
		if (stack->value[size_temp] < low)
			low = stack->value[size_temp];
		size_temp--;
	}
	return (low);
}

int	ft_get_high_number(t_stack *stack)
{
	int	high;
	int	size_temp;

	size_temp = stack->size;
	high = LONG_MAX;
	while (size_temp > 0)
	{
		if (stack->value[size_temp] >= high)
			high = stack->value[size_temp];
		size_temp--;
	}
	return (high);
}

int	ft_find_position(t_stack *stack, int to_find)
{
	int	size_temp;

	size_temp = stack->size;
	while (stack->value[size_temp] != to_find)
		size_temp--;
	return (size_temp);
}

int	ft_fit_stack(t_stack *stack_src, t_stack *stack_dst, t_stats *stats)
{	
	int	dst;
	int	src;

	dst = stack_dst->size;
	src = stack_src->size;
	stats->low = ft_get_lowest_number(stack_dst);
	stats->high_a = ft_get_high_number(stack_dst);
	if (stack_src->value[src] < stack_dst->value[dst]
		&& stack_dst->value[dst] == stats->low)
		return (1);
	if (stack_dst->value[dst] > stack_src->value[src]
		&& stack_dst->value[1] < stack_src->value[src])
		return (1);
	if (stack_src->value[src] > stats->high_a
		&& stack_dst->value[dst] == stats->low)
		return (1);
	return (0);
}

void	swap(t_stack *stack, int i, int j)
{
	int	temp;

	temp = stack->value[i];
	stack->value[i] = stack->value[j];
	stack->value[j] = temp;
}
