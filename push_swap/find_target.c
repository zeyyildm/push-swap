/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:19:06 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 17:22:57 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;
	int		bigger;
	int		max_val;
	int		min_val;
	int		target;
	t_list	*temp;

	temp_a = *stack_a;
	max_val = find_max(stack_b);
	min_val = find_min(stack_b);
	while (temp_a != NULL)
	{
		temp_b = *stack_b;
		target = 0;
		bigger = INT_MIN;
		if (temp_a->data > max_val || temp_a->data < min_val)
		{
			temp = *stack_b;
			while (temp != NULL)
			{
				if (temp->data == max_val)
				{
					target = temp->index;
					break ;
				}
				temp = temp->next;
			}
		}
		else
		{
			while (temp_b != NULL)
			{
				if (temp_b->data < temp_a->data && temp_b->data > bigger)
				{
					bigger = temp_b->data;
					target = temp_b->index;
				}
				temp_b = temp_b->next;
			}
		}
		temp_a->target = target;
		temp_a = temp_a->next;
	}
}

void	find_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	t_list	*temp_a;
	int		smaller;
	int		max_val;
	int		min_val;
	int		target;
	int		min_index;
	t_list	*temp;

	temp_b = *stack_b;
	max_val = find_max(stack_a);
	min_val = find_min(stack_a);
	while (temp_b != NULL)
	{
		temp_a = *stack_a;
		target = 0;
		smaller = INT_MAX;
		min_index = 0;
		if (temp_b->data > max_val || temp_b->data < min_val)
		{
			temp = *stack_a;
			while (temp != NULL)
			{
				if (temp->data == min_val)
				{
					min_index = temp->index;
					break ;
				}
				temp = temp->next;
			}
			target = min_index;
		}
		else
		{
			while (temp_a != NULL)
			{
				if ((temp_b->data < temp_a->data) && (temp_a->data < smaller))
				{
					smaller = temp_a->data;
					target = temp_a->index;
				}
				temp_a = temp_a->next;
			}
		}
		temp_b->target = target;
		temp_b = temp_b->next;
	}
}
