/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:13:29 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:01:41 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib.h"

int	ft_print_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		return (ft_putstr_fd("(null)", 1));
	}
	return (ft_putstr_fd(s, 1));
}

int	ft_print_dig(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	return (ft_putnbr_fd(d, 1));
}

int	ft_print_hex(va_list ap)
{
	unsigned long	ptr;

	ptr = va_arg(ap, unsigned long);
	if (ptr == 0)
	{
		return (ft_putstr_fd("(nil)", 1));
	}
	else
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		return (ft_putptr(ptr) + 2);
	}
}

int	ft_print_unsigned(va_list ap)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	return (ft_putnbr_unsigned_fd(i, 1));
}
