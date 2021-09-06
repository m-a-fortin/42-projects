/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:21:53 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/06 11:56:12 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_msg(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void	ft_check_error(t_stack *a, t_stack *b, t_stack *c, t_stats *stats)
{
	int	size;
	int	size_2;

	size = a->size;
	if (stats->error > 0)
		return ;
	while (size > 0)
	{
		size_2 = size - 1;
		while (size_2 > 0)
		{
			if (a->value[size] == a->value[size_2])
			{
				stats->error = 1;
				return ;
			}
			size_2--;
		}
		size--;
	}
	ft_check_max_min(a, stats);
	if (stats->error > 0)
		ft_deal_error(a, b, c, stats);
}

void	ft_check_max_min(t_stack *a, t_stats *stats)
{
	int		size;

	size = a->size;
	while (size > 0)
	{
		if (a->value[size] > INT_MAX || a->value[size] < INT_MIN)
			stats->error = 1;
		size--;
	}
}

void	ft_deal_error(t_stack *a, t_stack *b, t_stack *c, t_stats *stats)
{
	ft_free_ps(a, b, c, stats);
	ft_error_msg();
}

void	ft_free_ps(t_stack *a, t_stack *b, t_stack *c, t_stats *stats)
{
	if (a->value)
		free(a->value);
	if (b->value)
		free(b->value);
	if (c->value)
		free(c->value);
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free (c);
	if (stats)
		free(stats);
}
