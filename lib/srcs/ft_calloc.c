/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:33:44 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:00:54 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;

	if (size != 0 && count > 2147483647 / size)
		return (0);
	temp = (void *)malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero (temp, size * count);
	return (temp);
}
