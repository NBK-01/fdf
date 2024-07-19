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

static void	var_init(t_data *data, t_file **file, t_map *map)
{
	data->map = map;
	data->file = file;
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->zoom = 2;
	data->scale = 2;
	data->rot_y = 0.4;
	data->rot_x = 0.8;
	data->pos_y = 1;
	data->pos_x = 1;
	data->x = 0;
	data->y = 0;
}

/* Initializing program "FDF" -> checking if file exists, then 
* reading the map with read_file(see parse.c) 
* and init 2d array with map values */
int	init_fdf(char *path, t_file **file)
{
	int		fd;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit (ft_printf("Error: map doesn't exist / no permission\n"));
	else
	{
		if (read_file(path, file) > 0)
			exit (1);
		map = (t_map *)malloc(sizeof(t_map));
		init_matrix(file, map);
		init_window(map, file);
	}
	free_program(map, file);
	return (0);
}

void	init_window(t_map *map, t_file **file)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "fdf - nbk");
	if (!data.win_ptr)
		free(data.mlx_ptr);
	var_init(&data, file, map);
	mlx_key_hook(data.win_ptr, on_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, perp_render, &data);
	mlx_loop(data.mlx_ptr);
}
