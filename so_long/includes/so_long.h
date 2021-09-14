/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:14:31 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/14 19:15:30 by mafortin         ###   ########.fr       */
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
	int		nb_tiles;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	**images;
	int		img_index;
	int		done;
}				t_mlx;

typedef struct s_images
{
	void	*floor;
	void	*wall;
	void	*exit;
	void	*key;
}				t_images;

typedef struct s_player
{
	void	*front1;
	void	*front2;
	void	*front3;
	void	*left1;
	void	*left2;
	void	*left3;
	void	*right1;
	void	*right2;
	void	*right3;
	void	*back1;
	void	*back2;
	void	*back3;
	char	state[2];
	int		x;
	int		y;
	int		lost;
	int		collect;
	int		collect_goal;
	int		win;
	int		moves;
}			t_player;

typedef struct s_enemy
{
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	int		x;
	int		y;
	int		state;
	char	direction;
	int		spin;
	int		lost;
}				t_enemy;

typedef struct s_main
{
	t_map		*map_data;
	t_mlx		*ptrs;
	t_images	*tiles;
	t_player	*link;
	t_enemy		*bubble;
	int			time40;
	int			time60;
	int			time10;
	id_t		image_done;
}				t_main;


void	sl_parse_map_main(t_main *structs, char **argv, int argc);
void	sl_get_map(t_map *map_data, char *file_name, int line_count, t_main *structs);
int		sl_line_count(t_map *map_data, t_main *structs);
void	sl_fd_error(t_map *map_data, char **argv);
void	sl_map_error_main(t_main *structs);
void	sl_valid_map_limit(t_map *map_data, t_main *structs);
int		sl_map_asset_valid(t_map *map_data);
void	sl_args_error(t_main *structs);
void	sl_map_invalid(t_main *structs);
void	sl_argc_error(t_map *map_data);
void	sl_exit(t_main *structs);
int		sl_put_image_main(t_main *structs);
void	sl_place_map(t_map *map_data, t_mlx *ptrs);
int		sl_print_map(t_main *structs);
void	sl_print_tile(t_main *structs, void *tile, int x, int y);
void	sl_event_main(t_main *structs);
void	sl_print_loop(t_main *structs, int x, int y);
int		sl_print_player(t_main *structs);
void	sl_player_image(t_player *link, t_mlx *ptrs);
void	sl_enemy_image(t_enemy *bubble, t_mlx *ptrs);
int		sl_frame_timing(t_main *structs);
int		sl_print_enemy(t_main *structs);
void	sl_pathing_direction1(t_main *structs);
void	sl_pathing_direction2(t_main *structs);
void	sl_pathing_direction3(t_main *structs);
void	sl_pathing_direction4(t_main *structs);
void	sl_change_enemy_pos2(t_map *map_data, t_enemy *bubble);
void	sl_change_enemy_pos(t_map *map_data, t_enemy *bubble);
void	sl_move_up(t_map *map_data, t_player *link);
void	sl_move_up_linkmap(t_player *link, t_map *map_data);
void	sl_move_up_state(t_player *link);
void	sl_print_player_tile(t_main *structs, int x, int y);
void	sl_move_down(t_map *map_data, t_player *link);
void	sl_move_down_linkmap(t_player *link, t_map *map_data);
void	sl_move_down_state(t_player *link);
void	sl_move_right(t_map *map_data, t_player *link);
void	sl_move_right_linkmap(t_player *link, t_map *map_data);
void	sl_move_right_state(t_player *link);
void	sl_move_left(t_map *map_data, t_player *link);
void	sl_move_left_linkmap(t_player *link, t_map *map_data);
void	sl_move_left_state(t_player *link);
void	sl_manage_time(t_main *structs);
void	sl_print_player_tile2(t_main *structs, int x, int y);

#endif
