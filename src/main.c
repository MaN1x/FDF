/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:39:02 by maxim             #+#    #+#             */
/*   Updated: 2020/07/17 17:16:15 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

union 				u_byte
{
	unsigned int	i;
	char 	byte_value[4];
};

void	cpy_bits(char *dst, unsigned int data)
{
	union u_byte	byte;
	int				i;

	byte.i = data;
//	i = sizeof(unsigned int);
//	while (i--)
//	{
//		(dst)[i] = byte.byte_value[i];
//	//	printf("byte = %d\ti = %d\n", (unsigned char)byte.byte_value[i], i);
//	}

	i = 0;
	while (i != sizeof(unsigned int))
	{
		(dst)[i] = byte.byte_value[i];
		//printf("byte = %d\ti = %d\n", (unsigned char)byte.byte_value[i], i);
		i++;
	}
}

void	fill_line(char *image_start, int size_line,  unsigned int color)
{
	int i;

	i = 0;
	while (i <= size_line)
	{
		//printf("size line = %d\n", i);
		cpy_bits(&(image_start[i]), color);
		i+= 4;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		width;
	int		height;
	t_2vec	vec0;
	t_2vec	vec1;
	int i;
	int j;
	t_map map;

	width = 800;
	height = 600;
	map = read_map(argc, argv);
	mlx.mlx = mlx_init();
	mlx.windows.window = mlx_new_window(mlx.mlx, width, height, "FDF");
	mlx.windows.image = mlx_new_image(mlx.mlx, width, height);
	mlx.windows.image_start = mlx_get_data_addr(mlx.windows.image, &mlx.windows.bpp, &mlx.windows.size_line, &mlx.windows.endian);
	printf("bpp = %d\t size_line = %d\t endian = %d\n", mlx.windows.bpp, mlx.windows.size_line, mlx.windows.endian);

	vec0.x = 400;
	vec0.y = 300;

	vec1.x = vec0.x - 300;
	vec1.y = vec0.y - 10;

	line_draw(mlx.windows, 16711680, vec0, vec1);
	mlx_put_image_to_window(mlx.mlx, mlx.windows.window, mlx.windows.image, 0, 0);

	mlx_loop(mlx.mlx);



/*
 * print map
 */
	i = 0;
	j = 0;
	while (i < map.height)
	{
		while (j < map.width)
		{
			printf("%2d ", map.map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
/*
 * free map
 */
	i = 0;
	while (i < map.height)
		free(map.map[i++]);
	free(map.map);
	return (0);
}
