/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:30:33 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 15:03:08 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		sl_destroy_window(t_main *structs)
{
	mlx_destroy_window(structs->ptrs->mlx, structs->ptrs->win);
	sl_exit(structs);
	return (1);
}

int	sl_keypress_main(int key, t_main *structs)
{
	if (key == MAIN_ESC)
		sl_destroy_window(structs);
	return (key);
}

void	sl_event_main(t_main *structs)
{	
	mlx_hook(structs->ptrs->win, 17, 0L, sl_destroy_window, structs);
	mlx_hook(structs->ptrs->win, 2, 0L, sl_keypress_main, structs);
}