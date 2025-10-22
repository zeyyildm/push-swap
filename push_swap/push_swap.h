/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:00:48 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:11:08 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "../libft/libft.h"
# include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
	int				index;
	int				cost;
	int				target;
}					t_list;

t_list				*ft_lstnew(long content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				pop(t_list **head);
int					ft_lstsize(t_list *lst);
void				sa(t_list **lst);
void				sb(t_list **lst);
void				ss(t_list **lst_a, t_list **lst_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_b, t_list **stack_a);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
long				ft_atol(char *s);
void				is_duplicate(long *n, int counter);
char				*ft_strjoin2(char const *s1, char const *s2);
int					find_cost(t_list *stack, int target_index);
void				push_top_two(t_list **stack_a, t_list **stack_b);
int					find_max(t_list **stack_b);
int					find_min(t_list **stack_b);
void				find_index(t_list **stack_a, t_list **stack_b);
void				find_target(t_list **stack_a, t_list **stack_b);
void				total_cost(t_list **stack_a, t_list **stack_b);
t_list				*find_cheaper(t_list **stack_a);
void				rotate_a_to_top(t_list **stack_a, int index);
void				rotate_b_to_top(t_list **stack_b, int target);
void				sort_a_end(t_list **stack_a);
void				push_back_to_a(t_list **stack_a, t_list **stack_b);
void				find_target_a(t_list **stack_a, t_list **stack_b);
void				rotate_mixed(t_list **stack_a, t_list **stack_b, int index,
						int target);

#endif
