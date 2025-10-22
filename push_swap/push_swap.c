/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:00:05 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:10:51 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int			i;
	char		*storage;
	char		*tmp_storage;
	char		**tmp;
	int			counter;
	long int	*rt;
	int			j;
	t_list		**stack_a;
	t_list		**stack_b;
	t_list		*node;
	t_list		*cheaper;
	t_list		*end_value;
	int			min_index;

	if (ac < 2)
		return (0);
	i = 1;
	storage = (char *)calloc(1, sizeof(char));
	if (!storage)
		return (1);
	while (av[i] != NULL)
	{
		tmp_storage = storage;
		storage = ft_strjoin2(storage, av[i]);
		free(tmp_storage);
		i++;
	}
	tmp = ft_split(storage, ' ');
	if (!tmp)
	{
		free(storage);
		return (1);
	}
	counter = 0;
	i = 0;
	while (tmp[counter])
	{
		counter++;
	}
	if (counter == 0)
	{
		free(storage);
		return (0);
	}
	i = 0;
	rt = malloc(counter * sizeof(long int));
	if (!rt)
	{
		free(storage);
		return (1);
	}
	while (tmp[i])
	{
		rt[i] = ft_atol(tmp[i]);
		i++;
	}
	is_duplicate(rt, i);
	j = 0;
	stack_a = malloc(sizeof(t_list *));
	*stack_a = NULL;
	stack_b = malloc(sizeof(t_list *));
	*stack_b = NULL;
	while (j < i)
	{
		node = ft_lstnew(rt[j]);
		ft_lstadd_back(stack_a, node);
		j++;
	}
	if (ft_lstsize(*stack_a) <= 3)
	{
		if (ft_lstsize(*stack_a) == 2)
		{
			if ((*stack_a)->data > (*stack_a)->next->data)
				sa(stack_a);
		}
		else if (ft_lstsize(*stack_a) == 3)
			sort_a_end(stack_a);
		return (0);
	}
	push_top_two(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
	{
		find_index(stack_a, stack_b);
		find_target(stack_a, stack_b);
		total_cost(stack_a, stack_b);
		cheaper = find_cheaper(stack_a);
		rotate_mixed(stack_a, stack_b, cheaper->index, cheaper->target);
		pb(stack_b, stack_a);
	}
	sort_a_end(stack_a);
	push_back_to_a(stack_a, stack_b);
	end_value = *stack_a;
	min_index = 0;
	find_index(stack_a, stack_b);
	while (end_value != NULL)
	{
		if (find_min(stack_a) == end_value->data)
		{
			min_index = end_value->index;
		}
		end_value = end_value->next;
	}
	rotate_a_to_top(stack_a, min_index);
}
