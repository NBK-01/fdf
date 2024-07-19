/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:09:52 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/19 16:09:53 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;
	new[0] = (R(startcolor)) + round((pix * increment[0]));
	new[1] = (G(startcolor)) + round((pix * increment[1]));
	new[2] = (B(startcolor)) + round((pix * increment[2]));
	newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
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
			ft_put_pixel(data, w, h, 0x0c0c0c);
			w++;
		}
		h++;
	}
}
