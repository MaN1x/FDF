/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_and_mouse2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:06:44 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 17:44:10 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	pressed_key_z(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(matrix_rotate_z(0, 2),
													mlx->map.transform_matrix);
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
													mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
		&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
																	0, 0);
}

void	pressed_key_y(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(matrix_rotate_y(0, 2),
													mlx->map.transform_matrix);
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
												mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
																	0, 0);
}

void	pressed_key_x(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(matrix_rotate_x(0, 2),
													mlx->map.transform_matrix);
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
													mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
																	0, 0);
}

void	pressed_minus(t_mlx *mlx)
{
	mlx->map.scale -= 2;
	if (mlx->map.scale < 0)
		mlx->map.scale = 0;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
														mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
																	0, 0);
}

void	pressed_plus(t_mlx *mlx)
{
	mlx->map.scale += 2;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
												mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
																	0, 0);
}
