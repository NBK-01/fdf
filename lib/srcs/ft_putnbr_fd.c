/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:30:07 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:00:54 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		count;	

	count = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', &count);
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar(nb % 10 + '0', &count);
	return (count);
}
