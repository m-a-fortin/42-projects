/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:24:06 by mafortin          #+#    #+#             */
/*   Updated: 2021/09/08 21:37:20 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	sl_line_count(t_map *map_data)
{
	int		count;
	int		ret;
	char	buf[2];

	count = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(map_data->fd, buf, 1);
		if (ret < 0)
		{
			close(map_data->fd);
			return (-1);
		}
		buf[1] = '\0';
		if (buf[0] == '\n')
		count++;
	}
	close(map_data->fd);
	if (count == 1)
		sl_map_invalid(map_data);
	return (count + 1);
}

void	sl_get_map(t_map *map_data, char *file_name, int line_count)
{
	int	ret;
	int	index;
	int	len;

	len = 0;
	ret = 1;
	index = 0;
	map_data->fd = open(file_name, O_RDONLY);
	map_data->line = calloc(line_count + 1, sizeof(map_data->line));
	ret = get_next_line(map_data->fd, &map_data->line[index]);
	map_data->y = ft_strlen(map_data->line[index]);
	index++;
	while (ret > 0)
	{
		ret = get_next_line(map_data->fd, &map_data->line[index]);
		len = ft_strlen(map_data->line[index]);
		if (len != map_data->y)
			sl_map_invalid(map_data);
		index++;
	}
	map_data->x = line_count - 1;
	map_data->nb_tiles = (map_data->x + 1) * map_data->y;
	printf("Tiles:%d\n", map_data->nb_tiles);
	map_data->y--;
	close(map_data->fd);
}

int		sl_map_standards(char **map)
{
	int	index;
	int	player;
	int	exit;
	int	collect;

	index = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while (map[index])
	{
		player += ft_char_search(map[index], 'P');
		exit += ft_char_search(map[index], 'E');
		collect += ft_char_search(map[index], 'C');
		index++;
	}
	if (player == 0 || exit == 0 || collect == 0 || player > 1)
		return (-1);
	else
		return (1);
}

void	sl_valid_map(t_map *map_data)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (map_data->line[0][y])
	{
		if (map_data->line[0][y] != '1' || map_data->line[map_data->x][y] != '1')
			sl_map_invalid(map_data);
		y++;
	}
	while (map_data->line[x])
	{
		if (map_data->line[x][0] != '1' || map_data->line[x][map_data->y] != '1')
				sl_map_invalid(map_data);
		x++;
	}
	if (sl_map_standards(map_data->line) == -1)
		sl_map_invalid(map_data);
}

void	sl_map_main(t_map *map_data, char **argv, int argc)
{
	int	line_count;
	
	line_count = 0;
	if (argc != 2)
	{
		write(1,
			"Incorrect # of arguments Use: ./so_long \"name of map file\".ber\n",
			63);
		free(map_data);
		exit (0);
	}
	map_data->fd = open(argv[1], O_RDONLY);
	if (map_data->fd == -1)
		sl_fd_error(map_data, argv);
	else
		line_count = sl_line_count(map_data);
	sl_get_map(map_data, argv[1], line_count);
	sl_valid_map(map_data);
}
