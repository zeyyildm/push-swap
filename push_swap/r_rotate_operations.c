/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:19 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:11:47 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*temp;
	t_list	*head2;
	t_list	*temp2;

	if (*stack_a && (*stack_a)->next)
	{
		head = *stack_a;
		*stack_a = (*stack_a)->next;
		head->next = NULL;
		temp = *stack_a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = head;
	}
	if (*stack_b && (*stack_b)->next)
	{
		head2 = *stack_b;
		*stack_b = (*stack_b)->next;
		head2->next = NULL;
		temp2 = *stack_b;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = head2;
	}
	printf("rr\n");
}

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, temp2);
	printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *stack_b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, temp2);
	printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;
	t_list	*temp2;
	t_list	*last2;

	if (stack_a && *stack_a && (*stack_a)->next)
	{
		temp = *stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		temp2 = *stack_b;
		while (temp2->next->next != NULL)
			temp2 = temp2->next;
		last2 = temp2->next;
		temp2->next = NULL;
		last2->next = *stack_b;
		*stack_b = last2;
	}
	printf("rrr\n");
}
