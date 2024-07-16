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

/* Get height by counting the amount of lines in the map
* accessed from get next line func */
void	get_height(t_file **file, t_map *map)
{
	int	height;
	t_file	*head;

	head = (*file);
	height = 0;
	while (head)
	{
		head = head->next;
		height++;
	}
	map->height = height;
}

/* Getting width of map by splitting the first line */
void	get_width(t_file **file, t_map *map)
{
	int	width;
	t_file	*head;
	char	**temp;

	head = (*file);
	width = 0;
	temp = ft_split(head->line, ' ');
	while (temp[width])
		width++;
	map->width = width;
	while (width >= 0)
	{
		free(temp[width]);
		width--;
	}
	free(temp);
}

static void	set_matrix_values(char *line, int *axis)
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

void	init_matrix(t_file **file, t_map *map)
{
	int		i;
	t_file	*head;

	get_height(file, map);
	get_width(file, map);
	ft_printf("%d", map->width);
	map->mat = (int **)malloc(sizeof(int*) * (map->height + 1));
	i = 0;
	while(i <= map->height)
		map->mat[i++] = (int *)malloc(sizeof(int) * (map->width + 1));
	i = 0;
	head = (*file);
	while (head)
	{
		set_matrix_values(head->line, map->mat[i]);
		head = head->next;
		i++;
	}
}
