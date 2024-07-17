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
		map = (t_map*)malloc(sizeof(t_map));
		read_file(path, file);
		init_matrix(file, map);
		init_window(map);

	}
	free_program(map, file);
	return (0);
}
