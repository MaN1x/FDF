/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_and_mouse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 02:15:24 by maxim             #+#    #+#             */
/*   Updated: 2020/07/23 17:10:47 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "mlx.h"

static void	pressed_key_z(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(mlx->map.transform_matrix, matrix_rotate_z(0, 2));
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void	pressed_key_y(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(mlx->map.transform_matrix, matrix_rotate_y(0, 2));
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void	pressed_key_x(t_mlx *mlx)
{
	mlx->map.transform_matrix = mul_matrix33_matrix33(mlx->map.transform_matrix, matrix_rotate_x(0, 2));
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void	pressed_minus(t_mlx *mlx)
{
	mlx->map.scale -= 2;
	if (mlx->map.scale < 0)
		mlx->map.scale = 0;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void	pressed_plus(t_mlx *mlx)
{
	mlx->map.scale += 2;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void pressed_w(t_mlx *mlx)
{
	mlx->map.shift_y -= MOVE_Y;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void pressed_s(t_mlx *mlx)
{
	mlx->map.shift_y += MOVE_Y;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void pressed_d(t_mlx *mlx)
{
	mlx->map.shift_x += MOVE_X;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static void pressed_a(t_mlx *mlx)
{
	mlx->map.shift_x -= MOVE_X;
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx->windows.image = mlx_new_image(mlx->mlx, mlx->windows.width, mlx->windows.height);
	mlx->windows.image_start = mlx_get_data_addr(mlx->windows.image, &mlx->windows.bpp, &mlx->windows.size_line, &mlx->windows.endian);
	map_draw(mlx->windows, 0x00FF0000, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->windows.window, mlx->windows.image, 0, 0);
}

static int	key_press(int key, void *param)
{
	(t_mlx*)param;
	if (key == 120)
		pressed_key_x(param);
	else if (key == 121)
		pressed_key_y(param);
	else if (key == 122)
		pressed_key_z(param);
	else if (key == 65451)
		pressed_plus(param);
	else if (key == 65453)
		pressed_minus(param);
	else if (key == 119)
		pressed_w(param);
	else if (key == 115)
		pressed_s(param);
	else if (key == 97)
		pressed_a(param);
	else if (key == 100)
		pressed_d(param);
	return (0);
}

void	handle_keys_and_mouse(t_mlx *mlx)
{
	mlx_key_hook(mlx->windows.window, key_press, mlx);
}