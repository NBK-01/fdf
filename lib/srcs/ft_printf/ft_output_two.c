/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:13:29 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:01:44 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib.h"

int	ft_print_hex_lower(va_list ap)
{
	unsigned int	ptr;

	ptr = va_arg(ap, unsigned int);
	return (ft_putptr_lowercase(ptr));
}

int	ft_print_hex_upper(va_list ap)
{
	unsigned int	ptr;

	ptr = va_arg(ap, unsigned int);
	return (ft_putptr_uppercase(ptr));
}
