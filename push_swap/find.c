/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:18:04 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 17:22:32 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cost(t_list *stack, int target_index)
{
	int	cost;
	int	number_of_nodes;

	number_of_nodes = ft_lstsize(stack);
	if (target_index <= number_of_nodes / 2)
		cost = target_index;
	else
		cost = number_of_nodes - target_index;
	return (cost);
}

int	find_max(t_list **stack_b)
{
	int		max;
	t_list	*temp;

	max = (*stack_b)->data;
	temp = *stack_b;
	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}

int	find_min(t_list **stack_b)
{
	int		min;
	t_list	*temp;

	min = (*stack_b)->data;
	temp = *stack_b;
	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	find_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp1;
	t_list	*temp2;
	int		i;

	temp1 = *stack_a;
	temp2 = *stack_b;
	i = 0;
	while (temp1 != NULL)
	{
		temp1->index = i;
		temp1 = temp1->next;
		i++;
	}
	i = 0;
	while (temp2 != NULL)
	{
		temp2->index = i;
		temp2 = temp2->next;
		i++;
	}
}
