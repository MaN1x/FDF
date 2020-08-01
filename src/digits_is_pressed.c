/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_and_2_is_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:12:38 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 18:37:03 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"

void	iso_projection(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(
			matrix_rotate_x(NULL, ISO_X),
			matrix_rotate_z(NULL, ISO_Z));
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
												mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
							0, 0);
}

void	parallel_projection(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(matrix_rotate_x(NULL, 0),
									matrix_rotate_z(NULL, 0));
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
													mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
							0, 0);
}
