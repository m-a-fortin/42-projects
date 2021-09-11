/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:48 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 20:33:01 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_check_enemy_state(t_main *structs)
{
	if (structs->time10 == 10 || structs->time10 == 5)
	{
		structs->bubble->state++;
		if (structs->bubble->state == 6)
			structs->bubble->state = 1;
	}
	if (structs->bubble->state == 1)
		return (structs->bubble->frame1);
	if (structs->bubble->state == 2)
		return (structs->bubble->frame2);
	if (structs->bubble->state == 3)
		return (structs->bubble->frame3);
	if (structs->bubble->state == 4)
		return (structs->bubble->frame5);
	else
		return (structs->bubble->frame4);
}

void	sl_print_enemy_loop(t_main *structs, void *to_print)
{
	int x;
	int y;

	x = 0;
	while (structs->map_data->line[x])
	{
		y = 0;
		while (structs->map_data->line[x][y])
		{
			if (structs->map_data->line[x][y] == 'X')
			{
				sl_print_tile(structs, structs->tiles->floor, x, y);
				sl_print_tile(structs, to_print, x, y);
				structs->bubble->x = x * 75;
				structs->bubble->y = y * 75;
			}
			y++;
		}
		x++;
	}
}

int	sl_print_enemy(t_main *structs)
{
	void	*to_print;

	to_print = ft_check_enemy_state(structs);
	if (structs->time40 == 40)
		sl_change_enemy_pos(structs);
	sl_print_enemy_loop(structs, to_print);
	return (1);
}