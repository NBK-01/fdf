/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:21:29 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 09:21:31 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static void	set_ll(char *line, t_file **file)
{
	t_file	*new;

	new = ft_lstnew(line);
	ft_lstadd_back(file, new);
}

int	read_file(char *path, t_file **file)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Erorr: nothing to render"));
	while (line)
	{
		set_ll(line, file);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
