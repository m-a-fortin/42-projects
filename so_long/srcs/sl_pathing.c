/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_pathing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:39:37 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/16 13:41:09 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_pathing_direction1(t_main *structs)
{
	if (structs->bubble->direction == 'N')
	{
		if (structs->map_data->line[structs->bubble->x + 1]
			[structs->bubble->y] == '0'
			|| structs->map_data->line[structs->bubble->x + 1]
			[structs->bubble->y] == 'P')
			return ;
		else
		{
			structs->bubble->spin++;
			structs->bubble->direction = 'E';
			if (structs->bubble->spin >= 4)
				structs->bubble->direction = 'X';
		}
	}
	if (structs->bubble->direction == 'X')
		return ;
	sl_pathing_direction2(structs);
}

void	sl_pathing_direction2(t_main *structs)
{
	if (structs->bubble->direction == 'E')
	{
		if (structs->map_data->line[structs->bubble->x]
			[structs->bubble->y + 1] == '0'
			|| structs->map_data->line[structs->bubble->x]
			[structs->bubble->y + 1] == 'P')
			return ;
		else
		{
			structs->bubble->spin++;
			structs->bubble->direction = 'W';
			if (structs->bubble->spin >= 4)
				structs->bubble->direction = 'X';
		}
	}
	sl_pathing_direction3(structs);
}

void	sl_pathing_direction3(t_main *structs)
{
	if (structs->bubble->direction == 'W')
	{
		if (structs->map_data->line[structs->bubble->x]
			[structs->bubble->y - 1] == '0'
			|| structs->map_data->line[structs->bubble->x]
			[structs->bubble->y - 1] == 'P')
			return ;
		else
		{
			structs->bubble->spin++;
			structs->bubble->direction = 'S';
			if (structs->bubble->spin >= 4)
				structs->bubble->direction = 'X';
		}
	}
	sl_pathing_direction4(structs);
}

void	sl_pathing_direction4(t_main *structs)
{
	if (structs->bubble->direction == 'S')
	{
		if (structs->map_data->line[structs->bubble->x - 1]
			[structs->bubble->y] == '0'
			|| structs->map_data->line[structs->bubble->x - 1]
			[structs->bubble->y] == 'P')
			return ;
		else
		{
			structs->bubble->spin++;
			structs->bubble->direction = 'N';
			if (structs->bubble->spin >= 4)
				structs->bubble->direction = 'X';
		}
	}
	sl_pathing_direction1(structs);
}
