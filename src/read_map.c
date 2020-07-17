/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:42:54 by maxim             #+#    #+#             */
/*   Updated: 2020/07/15 00:16:12 by maxim            ###   ########.fr       */
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
	int		width;
	char	buf;

	width = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
		{
			close(fd);
			return (width);
		}
		if (buf != ' ')
			width++;
	}
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

static void		fill_map(t_map map, char *path)
{
	int		fd;
	int		i;
	int		j;
	char	*str;
	char	**line;

	i = 0;
	j = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		while (line[i])
		{
			map.map[j][i] = ft_atoi(line[i]);
			free(line[i]);
			i++;
		}
		i = 0;
		free(str);
		free(line);
		j++;
	}
}

t_map			read_map(int argc, char **argv)
{
	int		i;
	t_map	map;

	i = 0;
	map.width = get_map_width(argv[1]);
	map.height = get_map_height(argv[1]);
	map.map = (int**)malloc(sizeof(int*) * map.height);
	while (i != map.height)
		map.map[i++] = (int*)malloc(sizeof(int) * map.width);
	fill_map(map, argv[1]);
	return (map);
}
