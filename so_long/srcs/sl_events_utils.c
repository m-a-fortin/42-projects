/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:40:48 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/14 16:12:48 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_count_time(t_main *structs)
{
	structs->time40++;
	structs->time60++;
	structs->time10++;
	return (0);
}

void	sl_time_enemy_40(t_main *structs, t_enemy *bubble)
{
	int	height;
	int	width;

	if (bubble->state == 0)
	{
		bubble->state = 1;
		mlx_destroy_image(structs->ptrs->mlx, bubble->frame1);
		mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/enemy_two.xpm", &width, &height);
		mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, bubble->frame2, bubble->x, bubble->y);
	}
	if (bubble->state == 1)
	{
		bubble->state = 0;
		mlx_destroy_image(structs->ptrs->mlx, bubble->frame2);
		mlx_xpm_file_to_image(structs->ptrs->mlx, "assets/xpm/enemy_one.xpm", &width, &height);
		mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, bubble->frame1, bubble->x, bubble->y);
	}
}

void	sl_time_event_40(t_main *structs)
{
	sl_time_enemy_40(structs, structs->bubble);
	structs->time40 = 0;
}