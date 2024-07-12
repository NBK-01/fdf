/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:43:00 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 11:43:32 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init_window(char *av)
{
	t_data	data;
	
	(void)av;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "fdf - nbk");
	if (!data.win_ptr)
		free(data.mlx_ptr);
 
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	mlx_loop(data.mlx_ptr);
}

void	init_fdf(char *path)
{
	t_map	map;

	get_width(path, &map);
	get_height(path, &map);
	ft_printf("H:%d\n", map.height);
	ft_printf("W:%d\n", map.width);
	init_window(path);
}
