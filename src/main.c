/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:39:02 by maxim             #+#    #+#             */
/*   Updated: 2020/08/08 18:06:35 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"

static void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("wrong number of arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	check_args(argc, argv);
	mlx.windows.width = WINDOW_WIDTH;
	mlx.windows.height = WINDOW_HEIGHT;
	mlx.map = read_map(argv);
	mlx.map.shift_x = (int)mlx.windows.width / 2;
	mlx.map.shift_y = (int)mlx.windows.height / 2;
	mlx.mlx = mlx_init();
	mlx.windows.window = mlx_new_window(mlx.mlx, mlx.windows.width,
												mlx.windows.height, "FDF");
	mlx.windows.image = mlx_new_image(mlx.mlx, mlx.windows.width,
											mlx.windows.height);
	mlx.windows.image_start = mlx_get_data_addr(mlx.windows.image,
				&mlx.windows.bpp, &mlx.windows.size_line, &mlx.windows.endian);
	map_draw(mlx.windows, mlx.map);
	mlx_put_image_to_window(mlx.mlx, mlx.windows.window, mlx.windows.image,
																		0, 0);
	handle_keys_and_mouse(&mlx);
	mlx_loop(mlx.mlx);
	free(mlx.map.map);
	return (0);
}
