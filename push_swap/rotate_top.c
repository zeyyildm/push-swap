/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:15:41 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 17:22:02 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_top(t_list **stack_a, int index)
{
	int	s_size;
	int	reverse;

	s_size = ft_lstsize(*stack_a);
	if (index <= s_size / 2)
	{
		while (index > 0)
		{
			ra(stack_a);
			index--;
		}
	}
	else
	{
		reverse = s_size - index;
		while (reverse > 0)
		{
			rra(stack_a);
			reverse--;
		}
	}
}

void	rotate_b_to_top(t_list **stack_b, int target)
{
	int	s_size;
	int	reverse;

	s_size = ft_lstsize(*stack_b);
	if (target <= s_size / 2)
	{
		while (target > 0)
		{
			rb(stack_b);
			target--;
		}
	}
	else
	{
		reverse = s_size - target;
		while (reverse > 0)
		{
			rrb(stack_b);
			reverse--;
		}
	}
}

void	rotate_mixed(t_list **stack_a, t_list **stack_b, int index, int target)
{
	int	size_a;
	int	size_b;
	int	rotate_a_forward;
	int	rotate_b_forward;
	int	a_moves;
	int	b_moves;
	int	common;
	int	i;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	rotate_a_forward = (index <= size_a / 2);
	rotate_b_forward = (target <= size_b / 2);
	if (rotate_a_forward)
		a_moves = index;
	else
		a_moves = size_a - index;
	if (rotate_b_forward)
		b_moves = target;
	else
		b_moves = size_b - target;
	if (rotate_a_forward && rotate_b_forward)
	{
		if (a_moves < b_moves)
			common = a_moves;
		else
			common = b_moves;
		i = 0;
		while (i < common)
		{
			rr(stack_a, stack_b);
			i++;
		}
		i = 0;
		while (i < a_moves - common)
		{
			ra(stack_a);
			i++;
		}
		i = 0;
		while (i < b_moves - common)
		{
			rb(stack_b);
			i++;
		}
	}
	else if (!rotate_a_forward && !rotate_b_forward)
	{
		if (a_moves < b_moves)
			common = a_moves;
		else
			common = b_moves;
		i = 0;
		while (i < common)
		{
			rrr(stack_a, stack_b);
			i++;
		}
		i = 0;
		while (i < a_moves - common)
		{
			rra(stack_a);
			i++;
		}
		i = 0;
		while (i < b_moves - common)
		{
			rrb(stack_b);
			i++;
		}
	}
	else
	{
		rotate_a_to_top(stack_a, index);
		rotate_b_to_top(stack_b, target);
	}
}
