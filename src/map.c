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

int	get_height(char *path)
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
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	get_width(char *path)
{
	int	width;
	int	fd;
	char	*line;
	char	**temp;

	width = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	temp = ft_split(line, ' ');
	while (temp[width])
		width++;
	free(line);
	free(temp);
	close(fd);
	return (width);
}
#include <stdio.h>
void	get_z(char *line, int *axis)
{
	char	**z;
	int	i;

	z = ft_split(line, ' ');
	i = 0;
	while (z[i])
	{
		axis[i] = ft_atoi(z[i]);
		free(z[i]);
		i++;
	}
	free(z);
}

void	get_alt(char *path, t_map *map)
{
	int	i;
	int	fd;
	char	*line;

	map->height = get_height(path);
	map->width = get_width(path);
	map->mat = (int **)malloc(sizeof(int*) * (map->height + 1));
	i = 0;
	while(i <= map->height)
		map->mat[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	fd = open(path, O_RDONLY, 0);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		get_z(line, map->mat[i]);
		free(line);
		i++;
	}
	close(fd);
	map->mat[i] = NULL;
}
