/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:16:26 by maxim             #+#    #+#             */
/*   Updated: 2020/07/23 21:54:44 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	mul_matrix33_vec(t_matrix33 matrix, t_3vec *vec)
{
	t_3vec	tmp_vect;

	if (vec)
	{
		tmp_vect = *vec;
		vec->x = matrix.vec0.x * tmp_vect.x + matrix.vec1.x * tmp_vect.y + matrix.vec2.x * tmp_vect.z;
		vec->y = matrix.vec0.y * tmp_vect.x + matrix.vec1.y * tmp_vect.y + matrix.vec2.y * tmp_vect.z;
		vec->z = matrix.vec0.z * tmp_vect.x + matrix.vec1.z * tmp_vect.y + matrix.vec2.z * tmp_vect.z;
	}
}

t_matrix33	matrix_rotate_x(t_3vec *vec, float angle)
{
	t_matrix33	matrix;

	angle = (float)(angle * 3.1415)/180;
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

	angle = (float)(angle * 3.1415)/180;
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

	angle = (float)(angle * 3.1415)/180;
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

t_matrix33	mul_matrix33_matrix33(t_matrix33 matrix1, t_matrix33 matrix2)
{
	t_matrix33	result;

	result.vec0.x = matrix2.vec0.x * matrix1.vec0.x +
					matrix2.vec0.y * matrix1.vec1.x +
					matrix2.vec0.z * matrix1.vec2.x;

	result.vec0.y = matrix2.vec0.x * matrix1.vec0.y +
					matrix2.vec0.y * matrix1.vec1.y +
					matrix2.vec0.z * matrix1.vec2.y;

	result.vec0.z = matrix2.vec0.x * matrix1.vec0.z +
					matrix2.vec0.y * matrix1.vec1.z +
					matrix2.vec0.z * matrix1.vec2.z;

	result.vec1.x = matrix2.vec1.x * matrix1.vec0.x +
					matrix2.vec1.y * matrix1.vec1.x +
					matrix2.vec1.z * matrix1.vec2.x;

	result.vec1.y = matrix2.vec1.x * matrix1.vec0.y +
					matrix2.vec1.y * matrix1.vec1.y +
					matrix2.vec1.z * matrix1.vec2.y;

	result.vec1.z = matrix2.vec1.x * matrix1.vec0.z +
					matrix2.vec1.y * matrix1.vec1.z +
					matrix2.vec1.z * matrix1.vec2.z;

	result.vec2.x = matrix2.vec2.x * matrix1.vec0.x +
					matrix2.vec2.y * matrix1.vec1.x +
					matrix2.vec2.z * matrix1.vec2.x;

	result.vec2.y = matrix2.vec2.x * matrix1.vec0.y +
					matrix2.vec2.y * matrix1.vec1.y +
					matrix2.vec2.z * matrix1.vec2.y;

	result.vec2.z = matrix2.vec2.x * matrix1.vec0.z +
					matrix2.vec2.y * matrix1.vec1.z +
					matrix2.vec2.z * matrix1.vec2.z;
	return (result);
}

t_matrix33	matrix_scale(t_3vec *vec, float scale)
{
	t_matrix33	matrix;

	matrix.vec0.x = scale;
	matrix.vec0.y = 0;
	matrix.vec0.z = 0;

	matrix.vec1.x = 0;
	matrix.vec1.y = scale;
	matrix.vec1.z = 0;

	matrix.vec2.x = 0;
	matrix.vec2.y = 0;
	matrix.vec2.z = scale;

	mul_matrix33_vec(matrix, vec);
	return (matrix);
}

t_matrix33	matrix_orthographic(t_3vec *vec)
{
	t_matrix33	matrix;

	matrix.vec0.x = 1;
	matrix.vec0.y = 0;
	matrix.vec0.z = 0;

	matrix.vec1.x = 0;
	matrix.vec1.y = 1;
	matrix.vec1.z = 0;

	matrix.vec2.x = 0;
	matrix.vec2.y = 0;
	matrix.vec2.z = 0;

	mul_matrix33_vec(matrix, vec);
	return (matrix);
}
