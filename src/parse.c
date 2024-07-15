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

void	read_file(char *line, t_file **file)
{
	t_file *new;

	new = ft_lstnew(line);
	ft_lstadd_back(file, new);

}

void	store_file(char *path, t_file **file)
{
	int	fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		read_file(line, file);
		line = get_next_line(fd);
	}
	close(fd);
}
