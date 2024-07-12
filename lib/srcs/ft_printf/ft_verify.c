/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:10:27 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:01:22 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib.h"

int	ft_check(const char *str, va_list ap)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's'
				|| str[i + 1] == 'd' || str[i + 1] == 'p'
				|| str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == 'x' || str[i + 1] == 'X'
				|| str[i + 1] == '%'))
		{
			i += 2;
			count += ft_parse(str, i, ap);
		}
		else
		{
			write(1, &str[i++], 1);
			count += 1;
		}
	}
	return (count);
}

int	ft_parse(const char *str, int i, va_list ap)
{
	int	count;

	count = 0;
	if (str[i - 1] == 'c')
		count += ft_print_char(ap);
	else if (str[i - 1] == 's')
		count += ft_print_str(ap);
	else if (str[i - 1] == 'd' || str[i - 1] == 'i')
		count += ft_print_dig(ap);
	else if (str[i - 1] == 'p')
		count += ft_print_hex(ap);
	else if (str[i - 1] == 'u')
		count += ft_print_unsigned(ap);
	else if (str[i - 1] == 'x')
		count += ft_print_hex_lower(ap);
	else if (str[i - 1] == 'X')
		count += ft_print_hex_upper(ap);
	else if (str[i - 1] == '%')
		count += ft_putstr_fd("%", 1);
	return (count);
}
