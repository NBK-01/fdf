/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:34:43 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:00:54 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

int	ft_putptr(unsigned long ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
	{
		count += ft_putptr(ptr / 16);
	}
	ft_putchar(base[ptr % 16], &count);
	return (count);
}

int	ft_putptr_lowercase(unsigned int ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
	{
		count += ft_putptr_lowercase(ptr / 16);
	}
	ft_putchar(base[ptr % 16], &count);
	return (count);
}

int	ft_putptr_uppercase(unsigned int ptr)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (ptr >= 16)
	{
		count += ft_putptr_uppercase(ptr / 16);
	}
	ft_putchar(base[ptr % 16], &count);
	return (count);
}
