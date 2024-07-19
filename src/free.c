/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:39:49 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/16 11:39:50 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static void	del(char *line)
{
	line = NULL;
	free(line);
}

/* Util func to free 2d array after program end */
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->height)
	{
		free(map->mat[i]);
		i++;
	}
	free(map->mat);
	free(map);
}

/* Util func to free lines from GNL after using the linked list */
void	free_ll(t_file **file)
{
	t_file	*head;

	head = (*file);
	while (head)
	{
		free(head->line);
		head = head->next;
	}
}

/* Free all */
void	free_program(t_map *map, t_file **file)
{
	free_map(map);
	free_ll(file);
	ft_lstclear(file, del);
}
