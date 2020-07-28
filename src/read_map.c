/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:42:54 by maxim             #+#    #+#             */
/*   Updated: 2020/07/28 15:55:55 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"


static int		get_map_width(char *path)
{
	int		fd;
	int		flag;
	int		width;
	char	buf;

	width = 0;
	flag = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n' || ft_isspace(buf) && flag == 0)
		{
			width++;
			flag = 1;
		}
		if (ft_isdigit(buf))
			flag = 0;
		if (buf == '\n')
		{
			close(fd);
			return (width);
		}
	}
	close(fd);
	return (width);
}

static int		get_map_height(char *path)
{
	int		fd;
	int		height;
	char	buf;

	height = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
		if (buf == '\n')
			height++;
	close(fd);
	return (height);
}

static void		parse_color_and_z(t_3vec *vec, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == '\0')
	{
		vec->z = (float)ft_atoi(line);
		vec->color = DEFAULT_COLOR;
	}
	else if (line[i] == ',')
	{
		vec->z = (float)ft_atoi(line);
		vec->color = ft_atoi_hex(&line[i + 1]);
	}
}

static void		fill_map(t_map map, char *path)
{
	int		fd;
	int		i;
	int		j;
	int		k;
	char	*str;
	char	**line;

	i = 0;
	j = 0;
	k = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		while (line[i])
		{
			map.map[k].x = (float)i;
			map.map[k].y = (float)j;
			parse_color_and_z(&map.map[k], line[i]);
			k++;
			free(line[i]);
			i++;
		}
		i = 0;
		free(str);
		free(line);
		j++;
	}
	close(fd);
}

t_map			read_map(int argc, char **argv)
{
	t_map	map;

	map.scale = 10;
	map.transform_matrix = mul_matrix33_matrix33(matrix_rotate_x(NULL, ISO_X), matrix_rotate_z(NULL, ISO_Z));
	map.width = get_map_width(argv[1]);
	map.height = get_map_height(argv[1]);
	map.map = (t_3vec*)malloc(sizeof(t_3vec) * map.height * map.width);
	fill_map(map, argv[1]);
	return (map);
}
