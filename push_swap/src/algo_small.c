/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:01:42 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/24 13:50:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack *stack, t_stats *stats, char a_or_b)
{
	ft_get_stats(stack, stats);
	if (stack->value[stack->size] == stats->low)
	{
		if (stats->high_a == stack->value[stack->size - 1])
		{
			ft_move_sa_sb(stack, stack, a_or_b);
			ft_move_ra_rb(stack, stack, a_or_b);
		}
		return ;
	}
	if (stats->high_a == stack->value[stack->size])
	{
		ft_move_ra_rb(stack, stack, a_or_b);
		if (stats->low == stack->value[(stack->size - 1)])
			ft_move_sa_sb(stack, stack, a_or_b);
		return ;
	}
	if (stats->low == stack->value[(stack->size - 1)])
		ft_move_sa_sb(stack, stack, a_or_b);
	else
		ft_move_rra_rrb(stack, stack, a_or_b);
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{	
	ft_move_pa_pb(stack_a, stack_b, 'b');
	ft_move_pa_pb(stack_a, stack_b, 'b');
	ft_sort_three(stack_a, stats, 'a');
	while (stack_b->size > 0)
	{
		if (ft_fit_stack(stack_b, stack_a, stats) > 0)
			ft_move_pa_pb(stack_b, stack_a, 'a');
		else
			ft_move_ra_rb(stack_a, stack_b, 'a');
	}
	while (stack_a->value[stack_a->size] != stats->low)
		ft_rev_or_not_small(stack_a, stats, 'a');
}
