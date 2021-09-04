/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:13:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/01 14:59:46 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	long	*value;
	int		size;
}				t_stack;

typedef struct s_stats
{
	long	low;
	int		error;
	long	high_a;
	long	median;
	int		count;
	int		solved;
}				t_stats;

typedef struct s_big
{
	int	index;
	int	stop[100];
	int	index_2;
	int	stop_2[100];
}				t_big;

typedef struct s_swap
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
}				t_swap;

int		main(int argc, char **argv);
char	**ft_create_tab(char *argv, char **tab);
t_stack	*ft_make_stack_main(t_stack *a, int argc, char **argv, t_stats *stats);
t_stack	*ft_create_stack(char **tab, t_stack *stack_a, t_stats *stats);
void	ft_move_pa_pb(t_stack *src, t_stack *dest, char a_or_b_dest);
void	ft_move_sa_sb(t_stack *stack, t_stack *both, char a_or_b);
void	ft_move_ra_rb(t_stack *stack, t_stack *both, char a_or_b);
void	ft_move_rra_rrb(t_stack *stack, t_stack *both, char a_or_b);
void	ft_algo_main(t_stack *a, t_stack *b, t_stack *cpy, t_stats *stats);
int		ft_get_average(t_stack *stack_a);
void	ft_push_average_first(t_stack *a, t_stack *b, t_stats *stats);
void	ft_error_msg(void);
void	ft_check_error(t_stack *a, t_stack *b, t_stack *c, t_stats *stats);
void	ft_deal_error(t_stack *a, t_stack *b, t_stack *c, t_stats *stats);
void	ft_free_ps(t_stack *a, t_stack *b, t_stack *c, t_stats *stats);
int		ft_get_high_number(t_stack *stack);
void	ft_sort_three(t_stack *stack, t_stats *stats, char a_or_b);
void	ft_sort_five(t_stack *a, t_stack *b, t_stats *stats);
void	ft_sort_big(t_stack *a, t_stack *b, t_stats *stats);
int		ft_find_position(t_stack *stack, int high_or_low);
int		ft_fit_stack(t_stack *src, t_stack *dst, t_stats *stats);
void	ft_rev_or_not_big(t_stack *a, t_stack *b, t_stats *stats, char a_or_b);
void	ft_rev_or_not_small(t_stack *stack, t_stats *stats, char a_or_b);
int		ft_get_lowest_number(t_stack *stack);
void	ft_get_stats(t_stack *stack_a, t_stats *stats);
void	ft_sort_hundred_push(t_stack *a, t_stack *b, t_stats *stats);
int		ft_find_second_lowest(t_stack *stack, int low, int stack_size);
int		ft_find_fast_push(t_stack *stack_a, t_stats *stats);
void	ft_find_median(t_stack *stack, t_stack *cpy, t_stats *stats);
int		ft_push_median_high(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	ft_quick_sort(t_stack *stack, int low, int high);
int		ft_partition(t_stack *stack, int low, int high, int pivot);
void	swap(t_stack *stack, int i, int j);
void	ft_copy_stack(t_stack *stack, t_stack *cpy);
void	ft_push_median_low(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	ft_push_five(t_stack *a, t_stack *b, t_stats *stats, int index);
void	ft_five_small(t_stack *stack, t_stats *stats);
void	ft_sort_big_half(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	ft_push_small(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
void	ft_big_loop(t_stack *a, t_stack *b, t_stats *stats, t_big *big);
void	ft_push_back(t_stack *stack_a, t_stack *stack_b, int stop);
void	ft_solve_stack(t_stack *stack_a, t_stack *stack_b, t_stats *stats);
int		ft_is_sorted(t_stack *stack);
void	ft_redo_loop(t_stack *a, t_stack *b, t_stats *stats);
void	ft_nb_median_high(t_stack *stack_b, t_stats *stats);
void	ft_check_max_min(t_stack *a, t_stats *stats);

#endif