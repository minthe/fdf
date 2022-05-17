/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:05:23 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/17 18:36:12 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// handles the map and interactions with mlx
void	fdf(t_fdf *data)
{
	t_point	p1;
	t_point	p2;
	int x;
	int y;
	int scale;
	int scale_h;
	int offset_x;

	scale = 10;
	offset_x = 100;
	scale_h = 1;
	x = 0;
	y = 0;
	
	while(y < data->lines)
	{
		while(x < data->colums)
		{
			if (y < (data->lines - 1))
			{
				p1.x = x * scale + offset_x;
				p1.y = y * scale - offset_x + 50;
				p1.z = data->height[y][x] * scale_h;
				p2.x = x * scale + offset_x;
				p2.y = (y + 1) * scale - offset_x + 50;
				p2.z = data->height[y + 1][x] * scale_h;
				isometric(&p1.x, &p1.y, p1.z);
				isometric(&p2.x, &p2.y, p2.z);
				draw_line(data, &p2, &p1);
			}
			if (x < (data->colums - 1))
			{
				p1.x = x * scale + offset_x;
				p1.y = y * scale - offset_x + 50;
				p1.z = data->height[y][x] * scale_h;
				p2.x = (x + 1) * scale + offset_x;
				p2.y = y * scale - offset_x + 50;
				p2.z = data->height[y][x + 1] * scale_h;
				isometric(&p1.x, &p1.y, p1.z);
				isometric(&p2.x, &p2.y, p2.z);
				draw_line(data, &p2, &p1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image->img, 0, 0);
}
