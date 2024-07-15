/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:26:33 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/14 18:42:27 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

t_file	*ft_lstnew(char *content)
{
	t_file	*node;

	node = malloc(sizeof(t_file));
	if (!node)
		return (NULL);
	node->line = content;
	node->next = NULL;
	return (node);
}
