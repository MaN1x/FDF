/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:38:57 by maxim             #+#    #+#             */
/*   Updated: 2020/07/24 15:59:26 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define OFFSET_X 400
# define OFFSET_Y 300
# define MOVE_X 70
# define MOVE_Y 70
# define ISO_X 35.3
# define ISO_Y 0
# define ISO_Z 45

/*
 * =============================================================================
 * 								VECTORS
 */

typedef struct		s_2vec
{
	int x;
	int y;
}					t_2vec;

typedef struct		s_3vec
{
	float	x;
	float	y;
	float	z;
}					t_3vec;

/*
 * =============================================================================
 * 								MATRIX
 */

typedef struct		s_matrix33
{
	t_3vec vec0;
	t_3vec vec1;
	t_3vec vec2;
}					t_matrix33;

/*
 * =============================================================================
 * 					UNION FOR PUT_PIXEL_IN_IMAGE
 */

typedef union 		u_pixel
{
	int		color;
	char	byte[sizeof(int)];
}					t_pixel;

/*
 * =============================================================================
 * 								MAP STRUCT
 */
typedef struct		s_map
{
	int		width;
	int		height;
	int		shift_x;
	int		shift_y;
	float	scale;
	t_matrix33	transform_matrix;
	t_3vec	*map;
}					t_map;

/*
 * =============================================================================
 * 							MLX AND WINDOWS STRUCT
 */
typedef struct		s_windows
{
	void			*window;
	void			*image;
	char			*image_start;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_window	*next_window;
}					t_windows;

typedef struct		s_mlx
{
	void		*mlx;
	t_windows	windows;
	t_map		map;
}					t_mlx;

t_map				read_map(int argc, char **argv);
void				line_draw(t_windows window, int color, t_2vec vec0, t_2vec vec1);
void				mul_matrix33_vec(t_matrix33 matrix, t_3vec *vec);
t_matrix33			matrix_rotate_x(t_3vec *vec, float angle);
t_matrix33			matrix_rotate_y(t_3vec *vec, float angle);
t_matrix33			matrix_rotate_z(t_3vec *vec, float angle);
t_matrix33			mul_matrix33_matrix33(t_matrix33 matrix1, t_matrix33 matrix2);
t_matrix33			matrix_orthographic(t_3vec *vec);
void				map_draw(t_windows window, int color, t_map map);
void				handle_keys_and_mouse(t_mlx *mlx);
t_matrix33			matrix_scale(t_3vec *vec, float scale);

#endif
