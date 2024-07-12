/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:02:28 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:00:54 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar(n % 10 + '0', &count);
	return (count);
}
