/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:25:33 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/24 11:44:07 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;

	res = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstdelone(new, del);
		else
			ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
