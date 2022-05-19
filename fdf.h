/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:38:02 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/18 17:43:10 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <math.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

# define WINDOWS_W 1920
# define WINDOWS_H 1080

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_draw
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;
}	t_draw;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int		win_size_x;
	int		win_size_y;
	int		colums;
	int		lines;
	char	*map;
	int		**height;
	int		**color;
	int		offset_x;
	int		offset_y;
	int		scale;
	int		scale_h;
	t_image	*image;
}	t_fdf;

typedef struct s_point
{
	int x;
	int y;
	int z;
}	t_point;

int		draw_line(t_fdf *data, t_point *p1, t_point *p2);
int		count_lines(char *map);
int		count_colums(t_fdf *data);
void	fills_grid(t_fdf *data);
void	initialize_map(t_fdf *data);
void	fdf(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	exit_perror(char *c);
void	isometric(int *x, int *y, int z);
void	key_bindings(t_fdf *data);

#endif