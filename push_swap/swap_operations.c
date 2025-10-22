/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:16:47 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:12:09 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	(*lst) = temp2;
	printf("sa\n");
}

void	sb(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	temp2 = (*lst)->next;
	(*lst) = (*lst)->next;
	(*lst)->next = temp;
	temp->next = temp2->next;
	printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b)
{
	sa(lst_a);
	sb(lst_b);
	printf("ss\n");
}
