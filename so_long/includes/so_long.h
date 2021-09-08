/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:14:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/08 16:11:35 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_mac/mlx.h"
# include "so_long_key.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_map
{
	char	**line;
	int		fd;
	int		x;
	int		y;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct t_image;
{
	void	*ptr;
	int		*pos_x;
	int		*pos_y;
	int		state;
	char	tile_type;
}

void	sl_map_main(t_map *map, char **argv, int argc);
void	sl_get_map(t_map *map_data, char *file_name, int line_count);
int		sl_line_count(t_map *map_data);
void	sl_fd_error(t_map *map_data, char **argv);
void	sl_map_invalid(t_map *map_data);
void	sl_argc_error(t_map *map_data);
void	sl_exit(t_map *map_data, t_mlx *ptrs);
void	sl_print_map_main(t_map *map_data, t_mlx *ptrs);

#endif
