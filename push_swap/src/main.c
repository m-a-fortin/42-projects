/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:21:14 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/06 12:05:43 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo_main(t_stack *a, t_stack *b, t_stack *cpy, t_stats *stats)
{
	stats->solved = 0;
	if (a->size <= 3)
	{
		if (a->size == 2)
		{
			ft_move_sa_sb(a, b, 'a');
			return ;
		}
		ft_sort_three(a, stats, 'a');
		return ;
	}
	if (a->size <= 5)
	{
		ft_sort_five(a, b, stats);
		return ;
	}
	else
	{
		ft_find_median(a, cpy, stats);
		ft_sort_big(a, b, stats);
		return ;
	}
}

//6 arguments et +
void	ft_sort_big(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	t_big	*big;

	big = malloc(sizeof(t_big) * 1);
	stats->low = ft_get_lowest_number(stack_a);
	ft_push_median_low(stack_a, stack_b, stats);
	ft_big_loop(stack_a, stack_b, stats, big);
	while (stack_a->value[stack_a->size] != 1)
	{
		if (stack_a->value[stack_a->size] == stack_a->value[stack_a->size] + 1)
			ft_move_ra_rb(stack_a, stack_b, 'a');
		ft_move_pa_pb(stack_a, stack_b, 'b');
	}
	ft_big_loop(stack_a, stack_b, stats, big);
	free(big);
}

int	main(int argc, char **argv)
{
	t_swap	stacks;
	t_stats	*stats;

	stacks.a = ft_calloc(1, sizeof(t_stack));
	stacks.b = ft_calloc(1, sizeof(t_stack));
	stacks.c = ft_calloc(1, sizeof(t_stack));
	stats = ft_calloc(1, sizeof(t_stats));
	if (!stacks.a || !stacks.b || !stats || !stacks.c)
		ft_deal_error(stacks.a, stacks.b, stacks.c, stats);
	stats->error = 0;
	stacks.a = ft_make_stack_main(stacks.a, argc, argv, stats);
	ft_check_error(stacks.a, stacks.b, stacks.c, stats);
	if (stats->error > 0)
		ft_deal_error(stacks.a, stacks.b, stacks.c, stats);
	if (ft_is_sorted(stacks.a) == 0 || stacks.a->size <= 1)
	{
		ft_free_ps(stacks.a, stacks.b, stacks.c, stats);
		exit(0);
	}
	stacks.b->value = ft_calloc(stacks.a->size, sizeof(long) + 1);
	stacks.b->size = 0;
	ft_algo_main(stacks.a, stacks.b, stacks.c, stats);
	ft_free_ps(stacks.a, stacks.b, stacks.c, stats);
}
