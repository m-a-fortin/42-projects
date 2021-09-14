/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:56:37 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/14 17:28:28 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_move_left_state(t_player *link)
{
	if (link->state[0] == 'L')
	{
		if (link->state[1] == '1')
			link->state[1] = '2';
		else if (link->state[1] == '2')
			link->state[1] = '3';
		else if (link->state[1] == '3')
			link->state[1] = '2';
	}
	else
	{
		link->state[0] = 'L';
		link->state[1] = '1';
	}
}

void	sl_move_left_linkmap(t_player *link, t_map *map_data)
{	
	map_data->line[link->x][link->y - 1] = 'P';
	map_data->line[link->x][link->y] = '0';
	link->moves++;
}

void	sl_move_left(t_map *map_data, t_player *link)
{
	char temp;

	if (map_data->line[link->x][link->y - 1] != '1')
	{
		sl_move_left_state(link);
		if (link->state[1] != '1')
		{
			temp = map_data->line[link->x][link->y - 1];
			if (temp == 'C')
			{
				link->collect++;
				sl_move_left_linkmap(link, map_data);
			}
			else if (temp == 'X')
				link->lost = 1;
			else if (temp == 'E' && link->collect >= link->collect_goal)
				link->win = 1;
			if (temp == '0' || link->win == 1)
				sl_move_left_linkmap(link, map_data);
		}
	}
}