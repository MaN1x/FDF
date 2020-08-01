/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:42:54 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 18:15:24 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"

static void		parse_color_and_z(t_3vec *vec, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] == '\0')
	{
		vec->z = (float)ft_atoi(line);
		if (vec->z == 0)
			vec->color = COLOR_ZERO;
		else
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
	int		ijk[3];
	char	*str;
	char	**line;

	ijk[0] = 0;
	ijk[1] = 0;
	ijk[2] = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		line = ft_strsplit(str, ' ');
		while (line[ijk[0]])
		{
			map.map[ijk[2]].x = (float)ijk[0];
			map.map[ijk[2]].y = (float)ijk[1];
			parse_color_and_z(&map.map[ijk[2]++], line[ijk[0]]);
			free(line[ijk[0]++]);
		}
		ijk[0] = 0;
		free(str);
		free(line);
		ijk[1]++;
	}
	close(fd);
}

t_map			read_map(char **argv)
{
	t_map	map;

	map.scale = 10;
	map.transform_matrix = mul_matrix33_matrix33(matrix_rotate_x(NULL, ISO_X),
											matrix_rotate_z(NULL, ISO_Z));
	map.height = get_map_height(argv[1]);
	map.widths = get_map_widths(argv[1], map.height);
	map.amount_elements = get_amount_elements(map.height, map.widths);
	map.map = (t_3vec*)malloc(sizeof(t_3vec) * map.amount_elements);
	fill_map(map, argv[1]);
	return (map);
}
