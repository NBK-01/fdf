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

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}
/*
# define EVEN(nbr) (nbr % 2 == 0) ? 1 : 0;
# define MAX(nbr);
# define ABS(Value) ((Value < 0) ? -(Value) : (Value))

float	algo(float x, float y, float x1, float x2)
{
	int	x_next;
	int	y_next;

	x_next = x / x1;
	y_next = y / y2;
}*/
