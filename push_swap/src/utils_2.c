/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:14:33 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/24 15:01:39 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_or_not_big(t_stack *a, t_stack *b, t_stats *stats, char a_or_b)
{
	int	i;
	int	size_tmp;

	i = 0;
	size_tmp = b->size;
	stats->high_a = ft_get_high_number(b);
	while (b->value[size_tmp] != stats->high_a)
	{
		i++;
		size_tmp--;
	}
	if (i > b->size / 2)
		ft_move_rra_rrb(b, a, a_or_b);
	else
		ft_move_ra_rb(b, a, a_or_b);
}

void	ft_rev_or_not_small(t_stack *stack, t_stats *stats, char a_or_b)
{
	int	i;
	int	size_tmp;

	i = 0;
	size_tmp = stack->size;
	stats->low = ft_get_lowest_number(stack);
	while (stack->value[size_tmp] != stats->low)
	{
		i++;
		size_tmp--;
	}
	if (i > stack->size / 2)
		while (stack->value[stack->size] != stats->low)
			ft_move_rra_rrb(stack, stack, a_or_b);
	else
		while (stack->value[stack->size] != stats->low)
			ft_move_ra_rb(stack, stack, a_or_b);
}

void	ft_get_stats(t_stack *stack_a, t_stats *stats)
{
	stats->high_a = ft_get_high_number(stack_a);
	stats->low = ft_get_lowest_number(stack_a);
}

int	ft_is_sorted(t_stack *stack)
{
	int	size;
	int	i;

	size = stack->size;
	stack->value[0] = LONG_MAX;
	while (size > 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack->value[size] > stack->value[size - i])
				return (1);
			i++;
		}
		size--;
	}
	return (0);
}

void	ft_redo_loop(t_stack *a, t_stack *b, t_stats *stats)
{
	int	save;
	int	sent;

	sent = 0;
	stats->median = ft_get_average(b);
	stats->count = 0;
	save = ft_push_median_high(a, b, stats);
	ft_solve_stack(a, b, stats);
	ft_push_back(a, b, save);
}
