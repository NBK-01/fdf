/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:36:11 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/24 10:02:20 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	ft_lstadd_back(t_file **lst, t_file *new)
{
	t_file	*end;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new;
}
