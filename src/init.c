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

void	init_fdf(char *av)
{
	int	fd;
	char	*line;

	fd = open(av, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s", line);
		free(line);
	}
	close (fd);
}
