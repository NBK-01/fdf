/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:33:48 by nkanaan           #+#    #+#             */
/*   Updated: 2024/06/24 11:10:20 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"


t_file	*ft_lstlast(t_file *lst)
{
	t_file	*temp;

	temp = lst;
	if (!temp)
		return (NULL);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}
// #include <stdio.h>
// int main() {
//     // Create a sample linked list: 1 -> 2 -> 3 -> NULL
//     t_list *head = (t_list *)malloc(sizeof(t_list));
//     t_list *second = (t_list *)malloc(sizeof(t_list));
//     t_list *third = (t_list *)malloc(sizeof(t_list));

//     head->content = 1;
//     head->next = second;

//     second->content = 2;
//     second->next = third;

//     third->content = 3;
//     third->next = NULL;

//     // Call ft_lstlast to get the last element
//     t_list *last = ft_lstlast(head);

//     // Print the data of the last element
//     if (last != NULL) {
//         printf("Last element data: %d\n", last->content);
//     } else {
//         printf("List is empty.\n");
//     }

//     // Clean up: free allocated memory
//     free(head);
//     free(second);
//     free(third);

//     return 0;
// }
