/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:38:57 by maxim             #+#    #+#             */
/*   Updated: 2020/07/16 02:51:26 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

typedef union 		u_pixel
{
	int		color;
	char	byte[sizeof(int)];
}					t_pixel;

typedef struct		s_windows
{
	void			*window;
	void			*image;
	char			*image_start;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_image	*next_windows;
}					t_windows;

typedef struct		s_mlx
{
	void		*mlx;
	t_windows	windows;
}					t_mlx;

typedef struct		s_2vec
{
	int x;
	int y;
}					t_2vec;

typedef struct		s_3vec
{
	int	x;
	int	y;
	int	z;
}					t_3vec;

typedef struct		s_map
{
	int width;
	int height;
	int **map;
}					t_map;

t_map				read_map(int argc, char **argv);
void				line_draw(t_windows window, int color, t_2vec vec0, t_2vec vec1);

#endif
