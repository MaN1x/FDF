/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:38:57 by maxim             #+#    #+#             */
/*   Updated: 2020/08/08 18:08:01 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define DEFAULT_COLOR 0x00FFFFFF
# define MOVE_X 70
# define MOVE_Y 70
# define ISO_X 35.3
# define ISO_Y 0
# define ISO_Z 45
# define COLOR_ZERO 0x00FF0000

typedef struct		s_2vec
{
	int x;
	int y;
	int color;
}					t_2vec;

typedef struct		s_3vec
{
	float	x;
	float	y;
	float	z;
	int		color;
}					t_3vec;

typedef struct		s_matrix33
{
	t_3vec	vec0;
	t_3vec	vec1;
	t_3vec	vec2;
}					t_matrix33;

typedef struct		s_map
{
	int			amount_elements;
	int			*widths;
	int			height;
	int			shift_x;
	int			shift_y;
	float		scale;
	t_matrix33	transform_matrix;
	t_3vec		*map;
}					t_map;

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

t_map				read_map(char **argv);
void				line_draw(t_windows window, int color,
												t_2vec vec0, t_2vec vec1);
void				mul_matrix33_vec(t_matrix33 matrix, t_3vec *vec);
t_matrix33			matrix_rotate_x(t_3vec *vec, float angle);
t_matrix33			matrix_rotate_y(t_3vec *vec, float angle);
t_matrix33			matrix_rotate_z(t_3vec *vec, float angle);
t_matrix33			mul_matrix33_matrix33(t_matrix33 matrix1,
											t_matrix33 matrix2);
void				map_draw(t_windows window, t_map map);
void				handle_keys_and_mouse(t_mlx *mlx);
t_matrix33			matrix_scale(t_3vec *vec, float scale);
void				pressed_key_z(t_mlx *mlx);
void				pressed_key_x(t_mlx *mlx);
void				pressed_key_y(t_mlx *mlx);
void				pressed_minus(t_mlx *mlx);
void				pressed_plus(t_mlx *mlx);
void				pressed_w(t_mlx *mlx);
void				pressed_a(t_mlx *mlx);
void				pressed_s(t_mlx *mlx);
void				pressed_d(t_mlx *mlx);
void				iso_projection(t_mlx *mlx);
void				parallel_projection(t_mlx *mlx);
int					abs_my(int x);
int					get_map_height(char *path);
int					*get_map_widths(char *path, int map_height);
int					get_amount_elements(int height, const int *widths);

#endif
