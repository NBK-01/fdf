/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:43:11 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/18 15:43:35 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	perp_render(t_data *data)
{
	draw_background(data);
	draw(data, data->map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	if (keysym == 65364 && data->scale > 2)
		data->scale /= 2;
	if (keysym == 65362 && data->scale < 30)
		data->scale *= 2;
	if (keysym == 97)
		data->pos_x -= 10;
	if (keysym == 100)
		data->pos_x += 10;
	if (keysym == 119)
		data->pos_y -= 10;
	if (keysym == 115)
		data->pos_y += 10;
	if (keysym == 65451 && data->zoom < 450)
		data->zoom *= 1.1;
	if (keysym == 65453)
		data->zoom /= 1.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_program(data->map, data->file);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
