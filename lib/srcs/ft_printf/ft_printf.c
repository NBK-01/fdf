/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:50:26 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:01:35 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib.h"

int	ft_printf(const char *str, ...)
{	
	va_list	ap;

	va_start(ap, str);
	va_end(ap);
	return (ft_check(str, ap));
}
