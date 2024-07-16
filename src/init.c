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

void	init_window(void)
{
	t_data	data;
	
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

#include <stdio.h>
void	init_fdf(char *path, t_map *map, t_file **file)
{
	int	i = 0;
	int	j;
	store_file(path, file);
	get_alt(file, map);

	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d", map->mat[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

