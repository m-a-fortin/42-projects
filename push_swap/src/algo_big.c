/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:55:47 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/24 14:58:30 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_back(t_stack *stack_a, t_stack *stack_b, int stop)
{
	while (stack_a->value[stack_a->size] != stop)
		ft_move_pa_pb(stack_a, stack_b, 'b');
	if (stack_a->value[stack_a->size] == stop)
		ft_move_pa_pb(stack_a, stack_b, 'b');
}

void	ft_solve_stack(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	big;
	int	low;

	if (stack_b->size > 12)
		ft_redo_loop(stack_a, stack_b, stats);
	while (stack_b->size > 0)
	{	
		if (stats->solved == 0)
			low = ft_get_lowest_number(stack_b);
		else
			low = stack_a->value[1] + 1;
		ft_rev_or_not_big(stack_a, stack_b, stats, 'b');
		big = ft_get_high_number(stack_b);
		if (stack_b->value[stack_b->size] == big)
			ft_move_pa_pb(stack_b, stack_a, 'a');
		if (stack_b->value[stack_b->size] == low)
			ft_push_small(stack_a, stack_b, stats);
	}
	while (stack_a->value[stack_a->size] == stack_a->value[1] + 1)
		ft_move_ra_rb(stack_a, stack_b, 'a');
}

int	ft_nb_push(t_stack *stack_a, t_stack *stack_b, t_stats *stats, int *stop)
{
	int	index;

	index = 1;
	while (stack_b->size > 12)
	{
		stop[index] = ft_push_median_high(stack_a, stack_b, stats);
		index++;
	}
	return (index - 1);
}

void	ft_big_loop(t_stack *a, t_stack *b, t_stats *stats, t_big *big)
{
	big->index = ft_nb_push(a, b, stats, big->stop);
	while (big->index >= 0)
	{
		ft_solve_stack(a, b, stats);
		if (big->index == 0)
			break ;
		ft_push_back(a, b, big->stop[big->index]);
		big->index--;
		if (b->size > 12)
		{
			big->index_2 = ft_nb_push(a, b, stats, big->stop_2);
			while (big->index_2 >= 0)
			{
				ft_solve_stack(a, b, stats);
				if (big->index_2 == 0)
					break ;
				ft_push_back(a, b, big->stop_2[big->index_2]);
				big->index_2--;
			}
		}
	}
}
