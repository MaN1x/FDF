/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_and_mouse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 02:15:24 by maxim             #+#    #+#             */
/*   Updated: 2020/08/01 18:29:00 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

static int	close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->windows.image);
	mlx_destroy_window(mlx->mlx, mlx->windows.window);
	exit(0);
}

static int	key_press(int key, void *param)
{
	if (key == 120)
		pressed_key_x(param);
	else if (key == 121)
		pressed_key_y(param);
	else if (key == 122)
		pressed_key_z(param);
	else if (key == 119)
		pressed_w(param);
	else if (key == 115)
		pressed_s(param);
	else if (key == 97)
		pressed_a(param);
	else if (key == 100)
		pressed_d(param);
	else if (key == 65307)
		close(param);
	else if (key == 49)
		iso_projection(param);
	else if (key == 50)
		parallel_projection(param);
	return (0);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	if (x == 0)
		x = 0;
	if (y == 0)
		y = 0;
	if (button == 4)
		pressed_plus(param);
	else if (button == 5)
		pressed_minus(param);
	return (0);
}

void		handle_keys_and_mouse(t_mlx *mlx)
{
	mlx_key_hook(mlx->windows.window, key_press, mlx);
	mlx_mouse_hook(mlx->windows.window, mouse_press, mlx);
}
