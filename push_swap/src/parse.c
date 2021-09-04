/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:11:57 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/04 13:35:53 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_stack(char **tab, t_stack *stack_a, t_stats *stats)
{
	int	x;
	int	len;

	x = 0;
	stack_a->size = ft_matrice_size(tab);
	len = stack_a->size;
	stack_a->value = ft_calloc(stack_a->size, sizeof(long) + 1);
	while (tab[x])
	{
		if (ft_isdigit_string(tab[x]) == 0)
		{
			stats->error = 1;
			return (stack_a);
		}
		stack_a->value[len] = ft_atol(tab[x]);
		if (stack_a->value[len] <= stats->low)
			stats->low = stack_a->value[len];
		if (stack_a->value[len] >= stats->high_a)
			stats->high_a = stack_a->value[len];
		x++;
		len--;
	}
	return (stack_a);
}

char	**ft_create_tab(char *argv, char **tab)
{
	int	x;
	int	y;
	int	is_number;

	is_number = 0;
	x = 0;
	y = 0;
	tab = ft_split(argv, ' ');
	return (tab);
}

t_stack	*ft_make_stack_main(t_stack *a, int argc, char **argv, t_stats *stats)
{
	char	**tab;
	int		index;

	argv++;
	tab = NULL;
	index = 0;
	stats->low = LONG_MAX;
	stats->high_a = 1;
	if (argc == 2)
	{
		tab = ft_create_tab(*argv, tab);
		a = ft_create_stack(tab, a, stats);
		ft_free_tab(tab);
		return (a);
	}
	else
		a = ft_create_stack(argv, a, stats);
	return (a);
}
