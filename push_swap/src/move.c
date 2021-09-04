/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:15:26 by mafortin          #+#    #+#             */
/*   Updated: 2021/08/23 17:07:39 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_sa_sb(t_stack *stack, t_stack *both, char a_or_b)
{
	int	temp;

	temp = stack->value[stack->size];
	stack->value[stack->size] = stack->value[stack->size - 1];
	stack->value[stack->size - 1] = temp;
	if (a_or_b == 's')
	{
		write(1, "ss\n", 3);
		ft_move_sa_sb(both, stack, ' ');
	}
	if (a_or_b == 'a')
		write(1, "sa\n", 3);
	if (a_or_b == 'b')
		write(1, "sb\n", 3);
}

void	ft_move_pa_pb(t_stack *src, t_stack *dest, char a_or_b_dest)
{	
	if (!src->value)
		return ;
	dest->size++;
	dest->value[dest->size] = src->value[src->size];
	src->size--;
	if (a_or_b_dest == 'a')
		write(1, "pa\n", 3);
	if (a_or_b_dest == 'b')
		write(1, "pb\n", 3);
}

//rotate a - shift up all elements of stack a by 1. The first element becomes
//the last one
void	ft_move_ra_rb(t_stack *stack, t_stack *both, char a_or_b)
{
	int	temp;
	int	size;

	size = stack->size;
	temp = stack->value[stack->size];
	while (size > 0)
	{
		stack->value[size] = stack->value[size - 1];
		size--;
	}
	stack->value[1] = temp;
	if (a_or_b == 'r')
	{
		write(1, "rr\n", 3);
		ft_move_ra_rb(both, stack, ' ');
	}
	if (a_or_b == 'a')
		write(1, "ra\n", 3);
	if (a_or_b == 'b')
		write(1, "rb\n", 3);
}

void	ft_move_rra_rrb(t_stack *stack, t_stack *both, char a_or_b)
{
	int	temp;
	int	index;

	index = 1;
	temp = stack->value[index];
	while (index <= stack->size)
	{
		stack->value[index] = stack->value[index + 1];
		index++;
	}
	stack->value[stack->size] = temp;
	if (a_or_b == 'r')
	{
		write(1, "rrr\n", 4);
		ft_move_rra_rrb(both, stack, ' ');
	}
	if (a_or_b == 'a')
		write(1, "rra\n", 4);
	if (a_or_b == 'b')
		write(1, "rrb\n", 4);
}
