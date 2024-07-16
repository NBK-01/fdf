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

int	main(int ac, char *av[])
{
	t_file	*file;

	file = NULL;
	if (validate_args(ac, av) < 1)
	{
		init_fdf(av[1], &file);
		init_window();
	}
	return (0);
}
