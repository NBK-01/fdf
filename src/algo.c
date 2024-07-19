/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:10:06 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/19 16:10:07 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	draw(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			data->z = map->mat[y][x];
			data->color = gradient(0xfefefe, 0x00ff00, x, data->z);
			if (x < map->width - 1)
			{
				data->x = x;
				algo(x + 1, y, data);
			}
			if (y < map->height - 1)
			{
				data->y = y;
				algo(x, y + 1, data);
			}
			x++;
		}
		y++;
	}
}

void	iso_project(float *x, float *y, int z, t_data *data)
{
	*x = (*x - *y) * cos(data->rot_x);
	*y = (*x + *y) * sin(data->rot_y) - z * data->scale;
}

void	init_algo(float x, float y, t_data *data)
{
	if ((y + 1080 / 2 + data->pos_y) >= 0
		&& (x + 1920 / 2 + data->pos_x) < 1920
		&& (y + 1080 / 2 + data->pos_y) < 1080)
		ft_put_pixel(data, x + 1920 / 2 + data->pos_x,
			y + 1080 / 2 + data->pos_y, data->color);
}

void	algo(float x1, float y1, t_data *data)
{
	int		max;
	int		z1;
	float	x;
	float	y;

	x = data->x;
	y = data->y;
	z1 = data->map->mat[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	iso_project(&x, &y, data->z, data);
	iso_project(&x1, &y1, z1, data);
	data->x_next = x1 - x;
	data->y_next = y1 - y;
	max = MAX(MOD(data->x_next), MOD(data->y_next));
	data->x_next /= max;
	data->y_next /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		init_algo(x, y, data);
		x += data->x_next;
		y += data->y_next;
	}
}
