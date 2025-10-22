/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:57:44 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 17:20:44 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long content)
{
	t_list	*new_node;

	new_node = (t_list *)(malloc(sizeof(t_list)));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = (*lst);
	(*lst) = new;
	new->next = tmp;
}

void	pop(t_list **head)
{
	t_list	*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	(*head) = tmp->next;
	tmp->next = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
