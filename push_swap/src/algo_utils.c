/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:23:00 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/24 14:10:52 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_median_low(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	size;

	stats->count = 0;
	size = stack_a->size;
	stats->median = ft_get_average(stack_a);
	while (size > 0)
	{
		if (stack_a->value[size] <= stats->median)
			stats->count++;
		size--;
	}
	size = stack_a->size;
	while (stats->count > 0)
	{
		size = stack_a->size;
		if (stack_a->value[size] <= stats->median)
		{
			ft_move_pa_pb(stack_a, stack_b, 'b');
			stats->count--;
		}
		else
			ft_move_ra_rb(stack_a, stack_b, 'a');
	}
}

void	ft_push_small(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	ft_move_pa_pb(stack_b, stack_a, 'a');
	ft_move_ra_rb(stack_a, stack_b, 'a');
	stats->solved++;
}

void	ft_nb_median_high(t_stack *stack_b, t_stats *stats)
{
	int	size;

	size = stack_b->size;
	while (size > 0)
	{
		if (stack_b->value[size] >= stats->median)
			stats->count++;
		size--;
	}
}

int	ft_push_median_high(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	big;
	int	sent;

	sent = 0;
	stats->count = 0;
	stats->median = ft_get_average(stack_b);
	ft_nb_median_high(stack_b, stats);
	while (stats->count > 0)
	{
		if (stack_b->value[stack_b->size] >= stats->median)
		{
			if (sent == 0)
				big = stack_b->value[stack_b->size];
			ft_move_pa_pb(stack_b, stack_a, 'a');
			sent++;
			stats->count--;
		}
		else
			ft_move_ra_rb(stack_b, stack_a, 'b');
	}
	return (big);
}

int	ft_get_average(t_stack *stack)
{
	int	len;
	int	average;

	average = 0;
	len = stack->size;
	while (len > 0)
	{
		average += stack->value[len];
		len--;
	}
	return (average /= stack->size);
}
