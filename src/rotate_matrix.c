/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 17:31:02 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 17:31:02 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_matrix33	matrix_rotate_x(t_3vec *vec, float angle)
{
	t_matrix33	matrix;

	angle = (float)(angle * 3.1415) / 180;
	matrix.vec0.x = 1;
	matrix.vec0.y = 0;
	matrix.vec0.z = 0;
	matrix.vec1.x = 0;
	matrix.vec1.y = cosf(angle);
	matrix.vec1.z = sinf(angle);
	matrix.vec2.x = 0;
	matrix.vec2.y = -sinf(angle);
	matrix.vec2.z = cosf(angle);
	mul_matrix33_vec(matrix, vec);
	return (matrix);
}

t_matrix33	matrix_rotate_y(t_3vec *vec, float angle)
{
	t_matrix33	matrix;

	angle = (float)(angle * 3.1415) / 180;
	matrix.vec0.x = cosf(angle);
	matrix.vec0.y = 0;
	matrix.vec0.z = -sinf(angle);
	matrix.vec1.x = 0;
	matrix.vec1.y = 1;
	matrix.vec1.z = 0;
	matrix.vec2.x = sinf(angle);
	matrix.vec2.y = 0;
	matrix.vec2.z = cosf(angle);
	mul_matrix33_vec(matrix, vec);
	return (matrix);
}

t_matrix33	matrix_rotate_z(t_3vec *vec, float angle)
{
	t_matrix33	matrix;

	angle = (float)(angle * 3.1415) / 180;
	matrix.vec0.x = cosf(angle);
	matrix.vec0.y = sinf(angle);
	matrix.vec0.z = 0;
	matrix.vec1.x = -sinf(angle);
	matrix.vec1.y = cosf(angle);
	matrix.vec1.z = 0;
	matrix.vec2.x = 0;
	matrix.vec2.y = 0;
	matrix.vec2.z = 1;
	mul_matrix33_vec(matrix, vec);
	return (matrix);
}
