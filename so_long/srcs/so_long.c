/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:17:54 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/10 17:05:39 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_main	*structs;

	structs = malloc(sizeof(t_main));
	structs->ptrs = malloc(sizeof(t_mlx));
	structs->map_data = malloc(sizeof(t_map));
	structs->tiles = malloc(sizeof(t_images));
	structs->link = malloc(sizeof(t_player));
	sl_parse_map_main(structs->map_data, argv, argc);
	sl_print_map_main(structs);
	sl_enemy_main(structs);
	sl_player_main(structs);
	sl_event_main(structs);
	mlx_loop(structs->ptrs->mlx);
	sl_exit(structs);
	return (0);
}
