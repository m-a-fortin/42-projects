/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:05:48 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/13 17:37:40 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_check_enemy_state(t_main *structs)
{
	if (structs->time10 == 10)
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
				structs->bubble->x = x;
				structs->bubble->y = y;
			}
			y++;
		}
		x++;
	}
}

void	sl_change_enemy_pos(t_map *map_data, t_enemy *bubble)
{
	char temp;

	if (bubble->direction == 'N')
	{
		temp = map_data->line[bubble->x + 1][bubble->y];
		if (temp == 'P')
			bubble->lost = 1;
		map_data->line[bubble->x + 1][bubble->y] = map_data->line[bubble->x][bubble->y];
		map_data->line[bubble->x][bubble->y] = temp;
	}
	if (bubble->direction == 'E')
	{
		temp = map_data->line[bubble->x][bubble->y + 1];
		if (temp == 'P')
			bubble->lost = 1;
		map_data->line[bubble->x][bubble->y + 1] = map_data->line[bubble->x][bubble->y];
		map_data->line[bubble->x][bubble->y] = temp;
	}
	sl_change_enemy_pos2(map_data, bubble);
}

void	sl_change_enemy_pos2(t_map *map_data, t_enemy *bubble)
{
	char temp;

	if (bubble->direction == 'S')
	{
		temp = map_data->line[bubble->x - 1][bubble->y];
		if (temp == 'P')
			bubble->lost = 1;
		map_data->line[bubble->x - 1][bubble->y] = map_data->line[bubble->x][bubble->y];
		map_data->line[bubble->x][bubble->y] = temp;
	}
	if (bubble->direction == 'W')
	{
		temp = map_data->line[bubble->x][bubble->y - 1];
		if (temp == 'P')
			bubble->lost = 1;
		map_data->line[bubble->x][bubble->y - 1] = map_data->line[bubble->x][bubble->y];
		map_data->line[bubble->x][bubble->y] = temp;
	}
}

int	sl_print_enemy(t_main *structs)
{
	void	*to_print;

	to_print = ft_check_enemy_state(structs);
	if (structs->time40 == 40)
	{
		structs->bubble->spin = 0;
		sl_pathing_direction1(structs);
		sl_change_enemy_pos(structs->map_data, structs->bubble);
	}
	sl_print_enemy_loop(structs, to_print);
	return (1);
}