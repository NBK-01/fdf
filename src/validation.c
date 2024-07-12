/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:23:20 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 09:23:21 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	validate_args(int ac, char **av)
{
	int				i;
	char			*ext;
	unsigned int	start;

	i = -1;
	if (ac != 2)
		return (ft_printf("Error: wrong argument format\n"));
	else
	{
		while (av[1][++i])
		{
			if (av[1][i] == '.')
				start = i;
		}
		ext = ft_substr(av[1], start, ft_strlen(av[1]));
		if (ft_strncmp(ext, ".fdf", 4) != 0)
		{
			free(ext);
			return (ft_printf("Error: map ext should be .fdf\n"));
		}
	}
	free(ext);
	return (0);
}
