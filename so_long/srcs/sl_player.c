/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:28:46 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/14 19:15:27 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_player_image(t_player *link, t_mlx *ptrs)
{
	int	width;
	int	height;

	link->front1 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_front.xpm", &width, &height);
	link->front2 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_front1.xpm", &width, &height);
	link->front3 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_front2.xpm", &width, &height);
	link->left1 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_left.xpm", &width, &height);
	link->left2 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_left1.xpm", &width, &height);
	link->left3 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_left2.xpm", &width, &height);
	link->right1 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_right.xpm", &width, &height);
	link->right2 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_right1.xpm", &width, &height);
	link->right3 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_right2.xpm", &width, &height);
	link->back1 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_back.xpm", &width, &height);
	link->back2 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_back1.xpm", &width, &height);
	link->back3 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/link_back2.xpm", &width, &height);
}

void	sl_enemy_image(t_enemy *bubble, t_mlx *ptrs)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	bubble->frame1 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/enemy_one.xpm", &width, &height);
	bubble->frame2 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/enemy_two.xpm", &width, &height);
	bubble->frame3 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/enemy_three.xpm", &width, &height);
	bubble->frame4 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/enemy_four.xpm", &width, &height);
	bubble->frame5 = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/enemy_five.xpm", &width, &height);
}

void	sl_print_player_tile(t_main *structs, int x, int y)
{
	x *= 75;
	y *= 75;
	mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, "assets/xpm/link_front.xpm", y, x);
	if (structs->link->state[0] == 'U')
	{
		if (structs->link->state[1] == '1')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->back1, y, x);
		if (structs->link->state[1] == '2')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->back2, y, x);
		if (structs->link->state[1] == '3')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->back3, y, x);
	}
	if (structs->link->state[0] == 'R')
	{
		if (structs->link->state[1] == '1')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->right1, y, x);
		if (structs->link->state[1] == '2')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->right2, y, x);
		if (structs->link->state[1] == '3')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->right3, y, x);
	}
	sl_print_player_tile2(structs, x, y);
}

void	sl_print_player_tile2(t_main *structs, int x, int y)
{
	if (structs->link->state[0] == 'D')
	{
		if (structs->link->state[1] == '1')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->front1, y, x);
		if (structs->link->state[1] == '2')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->front2, y, x);
		if (structs->link->state[1] == '3')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->front3, y, x);
	}
	if (structs->link->state[0] == 'L')
	{
		if (structs->link->state[1] == '1')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->left1, y, x);
		if (structs->link->state[1] == '2')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->left2, y, x);
		if (structs->link->state[1] == '3')
			mlx_put_image_to_window(structs->ptrs->mlx, structs->ptrs->win, structs->link->left3, y, x);
	}
}

int	sl_print_player(t_main *structs)
{
	int	x;
	int	y;

	x = 0;
	if (structs->time60 == 60 && structs->link->state[1] != '1')
		structs->link->state[1] = '1';
	while (structs->map_data->line[x])
	{
		y = 0;
		while (structs->map_data->line[x][y])
		{
			if (structs->map_data->line[x][y] == 'P')
			{
				sl_print_tile(structs, structs->tiles->floor, x, y);
				sl_print_player_tile(structs, x, y);
				structs->link->x = x;
				structs->link->y = y;
			}
			y++;
		}
		x++;
	}
	return (1);
}
