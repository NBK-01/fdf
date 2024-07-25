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

/* Iterate to index of (.) creat substr of (.xyz) -> cmp to fdf. 
 * return err if != fdf */
static int	check_ext(char *av)
{
	int		i;
	int		start;
	char	*ext;

	i = -1;
	while (av[++i])
	{
		if (av[i] == '.')
		{
			start = i;
			ext = ft_substr(av, start, ft_strlen(av));
			if (ft_strcmp(ext, ".fdf") != 0)
			{
				free(ext);
				return (1);
			}
		free(ext);
		}
	}
	return (0);
}

/* Validating arguments, number of args + extension */
int	validate_args(int ac, char **av)
{
	if (ac != 2)
		return (ft_printf("Error: wrong argument format\n"));
	if (check_ext(av[1]) > 0)
		return (ft_printf("Error: map ext should be .fdf\n"));
	return (0);
}
