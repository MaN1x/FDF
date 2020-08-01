/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_is_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 19:11:13 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 18:23:44 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	pressed_w(t_mlx *mlx)
{
	mlx->map.shift_y -= MOVE_Y;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
												mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
							0, 0);
}

void	pressed_s(t_mlx *mlx)
{
	mlx->map.shift_y += MOVE_Y;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
												mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
							0, 0);
}

void	pressed_d(t_mlx *mlx)
{
	mlx->map.shift_x += MOVE_X;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
												mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
							0, 0);
}

void	pressed_a(t_mlx *mlx)
{
	mlx->map.shift_x -= MOVE_X;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width,
														mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image,
			&mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image,
							0, 0);
}
