/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement_up.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/15 19:38:08 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_move_up_state(t_player *link)
{
	if (link->state[0] == 'U')
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
		link->state[0] = 'U';
		link->state[1] = '1';
	}
}

void	sl_move_up_linkmap(t_player *link, t_map *map_data)
{	
	map_data->line[link->x - 1][link->y] = 'P';
	map_data->line[link->x][link->y] = '0';
	link->moves++;
}

void	sl_move_up(t_map *map_data, t_player *link)
{
	char	temp;

	if (map_data->line[link->x - 1][link->y] != '1')
	{
		sl_move_up_state(link);
		if (link->state[1] != '1')
		{
			temp = map_data->line[link->x - 1][link->y];
			if (temp == 'C')
				sl_move_up_linkmap(link, map_data);
			else if (temp == 'X')
				link->lost = 1;
			else if (temp == 'E' && link->collect >= link->collect_goal)
				link->win = 1;
			if (temp == '0' || link->win == 1 || temp == 'X')
				sl_move_up_linkmap(link, map_data);
		}
	}
}
