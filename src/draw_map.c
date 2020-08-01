/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:55:03 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 19:18:53 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static void		cpy_and_mul(t_3vec *vec_tmp, t_map map, t_matrix33 mtx)
{
	int	i;

	i = 0;
	while (i < map.amount_elements)
	{
		vec_tmp[i].x = map.map[i].x;
		vec_tmp[i].y = map.map[i].y;
		vec_tmp[i].z = map.map[i].z;
		mul_matrix33_vec(mtx, &vec_tmp[i]);
		i++;
	}
}

static t_2vec	*from_map_to_array(t_map map)
{
	t_2vec		*vec;
	t_matrix33	tmp;
	t_3vec		*vec_tmp;
	int			i;

	i = 0;
	tmp = mul_matrix33_matrix33(matrix_scale(NULL, map.scale),
														map.transform_matrix);
	vec_tmp = (t_3vec*)malloc(sizeof(t_3vec) * map.amount_elements);
	cpy_and_mul(vec_tmp, map, tmp);
	i = 0;
	vec = (t_2vec*)malloc(sizeof(t_2vec) * map.amount_elements);
	while (i < map.amount_elements)
	{
		vec[i].x = (int)vec_tmp[i].x + map.shift_x;
		vec[i].y = (int)vec_tmp[i].y + map.shift_y;
		vec[i].color = map.map[i].color;
		i++;
	}
	free(vec_tmp);
	return (vec);
}

static void		draw_hor_lines(t_windows window, t_map map, t_2vec *vec)
{
	int i;
	int j;
	int k;

	j = 0;
	i = 0;
	k = 0;
	while (j < map.height)
	{
		while (i < map.widths[j] - 1)
		{
			line_draw(window, vec[k].color, vec[k], vec[k + 1]);
			if (j != map.height - 1 && i < map.widths[j + 1])
				line_draw(window, vec[k].color, vec[k], vec[k + map.widths[j]]);
			i++;
			k++;
			if (i == map.widths[j] - 1 && j < map.height - 1)
				line_draw(window, vec[k].color, vec[k], vec[k + map.widths[j]]);
		}
		k++;
		i = 0;
		j++;
	}
}

void			map_draw(t_windows window, t_map map)
{
	t_2vec	*vec;

	vec = from_map_to_array(map);
	draw_hor_lines(window, map, vec);
	free(vec);
}
