/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:50:36 by maxim             #+#    #+#             */
/*   Updated: 2020/07/17 17:11:15 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	put_pixel_in_image(t_windows window, int color, int x, int y)
{
//	t_pixel	pixel;

	if (x < window.width && y < window.height && x > 0 && y > 0)
	{
//		pixel.color = color;
//		*(window.image_start + x * sizeof(int) + window.size_line * y) = pixel.byte[0];
//		*(window.image_start + x * sizeof(int) + window.size_line * y + 1) = pixel.byte[1];
//		*(window.image_start + x * sizeof(int) + window.size_line * y + 2) = pixel.byte[2];
//		*(window.image_start + x * sizeof(int) + window.size_line * y + 3) = pixel.byte[3];
		*((int*)(window.image_start + x * sizeof(int) + window.size_line * y)) = color;
	}
}

static void	line_draw_h(t_windows window, int color, t_2vec vec0, t_2vec vec1)
{
	int dx;
	int dy;
	int xi;
	int D;
	int xy[2];

	dx = vec1.x - vec0.x;
	dy = vec1.y - vec0.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = 2 * dx - dy;
	xy[0] = vec0.x;
	xy[1] = vec0.y;
	while (xy[1] <= vec1.y)
	{
		put_pixel_in_image(window, color, xy[0], xy[1]);
		if (D > 0)
		{
			xy[0] = xy[0] + xi;
			D = D - 2*dy;
		}
		D = D + 2*dx;
		xy[1]++;
	}
}

static void	line_draw_low(t_windows window, int color, t_2vec vec0, t_2vec vec1)
{
	int	dx;
	int	dy;
	int	yi;
	int D;
	int	xy[2];

	dx = vec1.x - vec0.x;
	dy = vec1.y - vec0.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = 2 * dy - dx;
	xy[1] = vec0.y;
	xy[0] = vec0.x;
	while (xy[0] <= vec1.x)
	{
		put_pixel_in_image(window, color, xy[0], xy[1]);
		if (D > 0)
		{
			xy[1] = xy[1] + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
		xy[0]++;
	}
}

static int	abs(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

void		line_draw(t_windows window, int color, t_2vec vec0, t_2vec vec1)
{
	if (abs(vec1.y - vec0.y) < abs(vec1.x - vec0.x))
	{
		if (vec0.x > vec1.x)
			line_draw_low(window, color, vec1, vec0);
		else
			line_draw_low(window, color, vec0, vec1);
	}
	else
	{
		if (vec0.y > vec1.y)
			line_draw_h(window, color, vec1, vec0);
		else
			line_draw_h(window, color, vec0, vec1);
	}
}
