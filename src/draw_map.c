/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:55:03 by maxim             #+#    #+#             */
/*   Updated: 2020/07/23 23:55:03 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

//static int	clipping(t_map map, t_2vec vec)
//{
//
//}

static t_2vec	*from_map_to_array(t_map map)
{
	t_2vec		*vec;
	t_matrix33	tmp;
	t_3vec		*vec_tmp;
	int			i;

	i = 0;
	tmp = mul_matrix33_matrix33(matrix_scale(NULL, map.scale), map.transform_matrix);
	vec_tmp = (t_3vec*)malloc(sizeof(t_3vec) * map.width * map.height);
	while (i < map.width * map.height)
	{
		vec_tmp[i].x = map.map[i].x;
		vec_tmp[i].y = map.map[i].y;
		vec_tmp[i].z = map.map[i].z;
		mul_matrix33_vec(tmp, &vec_tmp[i]);
		i++;
	}
	i = 0;
	vec = (t_2vec*)malloc(sizeof(t_2vec) * map.width * map.height);
	while (i < map.width * map.height)
	{
		vec[i].x = (int)vec_tmp[i].x + map.shift_x;
		vec[i].y = (int)vec_tmp[i].y + map.shift_y;
		i++;
	}
	free(vec_tmp);
	return (vec);
}

static void	draw_hor_lines(t_windows window, int color, t_map map, t_2vec *vec)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	k = 0;
	while (j < map.height)
	{
		while (i < map.width - 1)
		{
			line_draw(window, color, vec[k], vec[k + 1]);
			i++;
			k++;
		}
		k++;
		i = 0;
		j++;
	}
}

static void	draw_ver_lines(t_windows window, int color, t_map map, t_2vec *vec)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < map.width)
	{
		while (i < map.height - 1)
		{
			line_draw(window, color, vec[k], vec[k + map.width]);
			i++;
			k+= map.width;
		}
		i = 0;
		j++;
		k = j;
	}
}

void		map_draw(t_windows window, int color, t_map map)
{
	t_2vec	*vec;

	vec = from_map_to_array(map);
	draw_hor_lines(window, color, map, vec);
	draw_ver_lines(window, color, map, vec);

	free(vec);
}
