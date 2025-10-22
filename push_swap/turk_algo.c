/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:01:38 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 17:20:57 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	total_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		cost1;
	int		cost2;

	temp = *stack_a;
	while (temp != NULL)
	{
		cost1 = find_cost(*stack_a, temp->index);
		cost2 = find_cost(*stack_b, temp->target);
		temp->cost = cost1 + cost2;
		temp = temp->next;
	}
}

t_list	*find_cheaper(t_list **stack_a)
{
	t_list	*temp;
	int		min_cost;
	t_list	*cheaper;

	if (!stack_a)
		return (NULL);
	temp = *stack_a;
	min_cost = INT_MAX;
	cheaper = temp;
	while (temp != NULL)
	{
		if (temp->cost < min_cost || (temp->cost == min_cost
				&& temp->index < cheaper->index))
		{
			min_cost = temp->cost;
			cheaper = temp;
		}
		temp = temp->next;
	}
	return (cheaper);
}

void	sort_a_end(t_list **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return ;
	if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
		return ;
	}
	if (((*stack_a)->next->data) < ((*stack_a)->data))
		sa(stack_a);
	if ((*stack_a)->next->next->data < (*stack_a)->data)
		rra(stack_a);
	if ((*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheaper;

	while (ft_lstsize(*stack_b) > 0)
	{
		find_index(stack_a, stack_b);
		find_target_a(stack_a, stack_b);
		total_cost(stack_b, stack_a);
		cheaper = find_cheaper(stack_b);
		rotate_mixed(stack_a, stack_b, cheaper->target, cheaper->index);
		pa(stack_a, stack_b);
	}
}
