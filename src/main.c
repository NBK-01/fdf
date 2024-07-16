/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:18:55 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 11:40:31 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	free_line(t_file **file)
{
	t_file	*head;

	head = (*file);
	while (head)
	{
		free(head->line);
		head = head->next;
	}
}
// CLEAN THIS 
int	main(int ac, char *av[])
{
	t_map	*map;
	t_file	*file;

	file = NULL;
	if (validate_args(ac, av) < 1)
	{
		map = (t_map*)malloc(sizeof(t_map));
		init_fdf(av[1], map, &file);
	}
	free_line(&file);
	ft_lstclear(&file, del);
	int	i = 0;
	while (i <= map->height)
	{
		free(map->mat[i]);
		i++;
	}
	//free(map->mat[i]);
	free(map->mat);
	free(map);
	init_window();
	return (0);
}


void	del(char *line)
{
	line = NULL;
	free(line);
}
