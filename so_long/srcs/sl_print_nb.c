/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpst <hpst@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:30:07 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/15 19:39:49 by hpst             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	sl_number_images(t_number *number_data, t_mlx *ptrs)
{
	int	width;
	int	height;

	number_data->zero = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/0.xpm", &width, &height);
	number_data->one = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/1.xpm", &width, &height);
	number_data->two = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/2.xpm", &width, &height);
	number_data->three = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/3.xpm", &width, &height);
	number_data->four = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/4.xpm", &width, &height);
	number_data->five = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/5.xpm", &width, &height);
	number_data->six = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/6.xpm", &width, &height);
	number_data->seven = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/7.xpm", &width, &height);
	number_data->eight = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/8.xpm", &width, &height);
	number_data->nine = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/9.xpm", &width, &height);
	number_data->numbers = mlx_xpm_file_to_image(ptrs->mlx, "assets/xpm/moves.xpm", &width, &height);
}

void	sl_print_moves_nb(t_main *structs, t_number *number_data, int moves)
{

	int	nb;

	nb = moves;
	if (nb > 9)
	{
		sl_print_moves_nb(structs, number_data, nb / 10);
		sl_print_moves_nb(structs, number_data, nb % 10);
	}
	else
	{
		sl_print_tile_moves(structs, number_data->x, number_data->y, nb);
		number_data->y++;
	}
}

void	sl_print_tile_moves(t_main *structs, int x, int y, int nb)
{
	if (nb == 0)
		sl_print_tile(structs, structs->number_data->zero, x, y);
	if (nb == 1)
		sl_print_tile(structs, structs->number_data->one, x, y);
	if (nb == 2)
		sl_print_tile(structs, structs->number_data->two, x, y);
	if (nb == 3)
		sl_print_tile(structs, structs->number_data->three, x, y);
	if (nb == 4)
		sl_print_tile(structs, structs->number_data->four, x, y);
	if (nb == 5)
		sl_print_tile(structs, structs->number_data->five, x, y);
	if (nb == 6)
		sl_print_tile(structs, structs->number_data->six, x, y);
	if (nb == 7)
		sl_print_tile(structs, structs->number_data->seven, x, y);
	if (nb == 8)
		sl_print_tile(structs, structs->number_data->eight, x, y);
	if (nb == 9)
		sl_print_tile(structs, structs->number_data->nine, x, y);
}

void	sl_print_moves(t_main *structs)
{
	int	x;

	structs->number_data->y = 4;
	x = structs->number_data->x;
	sl_print_tile(structs, structs->number_data->numbers, x, 0);
	sl_print_moves_nb(structs, structs->number_data, structs->link->moves);
}
