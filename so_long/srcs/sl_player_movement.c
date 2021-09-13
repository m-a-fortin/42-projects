/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:43 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/13 19:09:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_move_up_frame(t_map *map_data, t_player *link)
{
	if (link->state[0] == 'U')
	{
		if (link->state[1] == '1')
			link->state[1] == '2';
		else if (link->state[1] == '2')
			link->state[1] == '3';
		else if (link->state[1] == '3')
			link->state[1] == '2';
	}
	else
	{
		link->state[0] = 'U';
		link->state[1] = '1';
	}
}

void	sl_move_up(t_map *map_data, t_player *link)
{
	char temp;

	if (map_data->line[link->x + 1][link->y] != '1')
	{
		sl_move_up_frame(map_data, link);
		if (link->state[1] != '1')
		{
		}

}