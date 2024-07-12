/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:34:03 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/26 15:00:54 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (!dst && dstsize == 0)
		return (src_len);
	if (dest_len >= dstsize)
		return (src_len + dstsize);
	else
		dstsize -= dest_len;
	ft_strlcpy(dst + dest_len, src, dstsize);
	return (dest_len + src_len);
}
