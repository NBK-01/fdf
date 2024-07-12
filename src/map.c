/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:22:58 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 11:41:03 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	get_height(char *path, t_map *map)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		exit(ft_printf("error opening map"));
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free(line);
	}
	if (i > 0)
		map->height = i;
	close(fd);
}

void	get_width(char *path, t_map *map)
{
	int	i;
	int	width;
	int	fd;
	char	*line;

	i = 0;
	width = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	ft_printf("LINE: %s\n", line);
	while (line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\r' && line[i] != '\v')
			width++;
		i++;
	}
	map->width = width;
	free(line);
	close(fd);
}
