/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:39:02 by maxim             #+#    #+#             */
/*   Updated: 2020/07/23 23:33:53 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.windows.width = 800;
	mlx.windows.height = 600;

/*
 * =============================================================================
 * 								READ MAP
 * =============================================================================
 */

	mlx.map = read_map(argc, argv);

/*
 * =============================================================================
 * 								MLX INIT
 * =============================================================================
 */

	mlx.mlx = mlx_init();
	mlx.windows.window = mlx_new_window(mlx.mlx, mlx.windows.width, mlx.windows.height, "FDF");
	mlx.windows.image = mlx_new_image(mlx.mlx, mlx.windows.width, mlx.windows.height);
	mlx.windows.image_start = mlx_get_data_addr(mlx.windows.image, &mlx.windows.bpp, &mlx.windows.size_line, &mlx.windows.endian);


/*
 * =============================================================================
 * 								MAP DRAW
 * =============================================================================
 */



	map_draw(mlx.windows, mlx.map);



	mlx_put_image_to_window(mlx.mlx, mlx.windows.window, mlx.windows.image, 0, 0);
	handle_keys_and_mouse(&mlx);
	mlx_loop(mlx.mlx);



/*
 * free map
 */
	free(mlx.map.map);
	return (0);
}
