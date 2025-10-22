/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:11:56 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:10:17 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top_two(t_list **stack_a, t_list **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	head = (*stack_b);
	pop(stack_b);
	ft_lstadd_front(stack_a, head);
	printf("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*head;

	head = (*stack_a);
	pop(stack_a);
	ft_lstadd_front(stack_b, head);
	printf("pb\n");
}
