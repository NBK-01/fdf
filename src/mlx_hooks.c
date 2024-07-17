/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:43:11 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 11:43:12 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

int gradient(int startcolor, int endcolor, int len, int pix)
{
    double increment[3];
    int new[3];
    int newcolor;

    increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

    new[0] = (R(startcolor)) + (pix * increment[0]);
    new[1] = (G(startcolor)) + (pix * increment[1]);
    new[2] = (B(startcolor)) + (pix * increment[2]);

    newcolor = RGB(new[0], new[1], new[2]);

    return (newcolor);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_background(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h <= 1080)
	{
		w = 0;
		while (w <= 1920)
		{
			ft_put_pixel(data, w, h, 0x000000);
			w++;
		}
		h++;
	}
}

int	render(t_data *data)
{
	draw_background(data);
	draw(data, data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	on_mouse(int mocode, t_data *data)
{
	if (mocode == 4)
		data->zoom *= 1.1;
	if (mocode == 5)
		data->zoom /= 1.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	return (1);
}

void	init_window(t_map *map)
{
	t_data	*data;
	
	data = (t_data*)malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "fdf - nbk");
	if (!data->win_ptr)
		free(data->mlx_ptr);
	data->map = map;
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->zoom = 40;
	data->rot = 0.9;
	data->pos_y = 0;
	data->pos_x = 0;

	//draw(data, map);
	mlx_mouse_hook(data->win_ptr, on_mouse, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_key_hook(data->win_ptr, on_keypress, data);
	mlx_loop(data->mlx_ptr);
}


#include <signal.h>
int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	if (keysym == 65362)
		data->pos_y -= 10;
	if (keysym == 65361)
		data->pos_x -= 10;
	if (keysym == 65364)
		data->pos_y += 10;
	if (keysym == 65363)
		data->pos_x += 10;
	if (keysym == 119)
		data->rot += 0.1;
	if (keysym == 115)
		data->rot -= 0.1;
	if (keysym == 65451)
		data->zoom *= 1.1;
	if (keysym == 65453)
		data->zoom /= 1.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	return (0);
}


int	on_destroy(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	mlx_destroy_window(data->win_ptr, data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->win_ptr);
	exit (0);
}

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
			if (x < map->width - 1)
				algo(x, y, x + 1, y, data, map);
			if (y < map->height - 1)
				algo(x, y, x, y + 1, data, map);
			x++;
		}
		y++;
	}
}


void	iso_project(float *x, float *y, int z, t_data *data)
{
	*x = (*x - *y) * cos(data->rot);
	*y = (*x + *y) * sin(data->rot) - z;
}

void	algo(float x, float y, float x1, float y1, t_data *data, t_map *map)
{
	float	x_next;
	float	y_next;
	int	max;
	int	z;
	int	z1;

	z = map->mat[(int)y][(int)x];
	z1 = map->mat[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	iso_project(&x, &y, z, data);
	iso_project(&x1, &y1, z1, data);

	int col = gradient(0x00ff00, 0x2FA8F9, x1, x);
	data->color = (z) ? col : 0xffffff;
	x_next = x1 - x;
	y_next = y1 - y;
	max = MAX(MOD(x_next), MOD(y_next));
	x_next = x_next / max;
	y_next = y_next / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		ft_put_pixel(data, x + 1920 / 2 + data->pos_x, y + 1080 / 2 + data->pos_y, data->color);
		x += x_next;
		y += y_next;
	}
}
