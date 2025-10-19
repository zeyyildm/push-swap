#include "push_swap.h"
#include <stdio.h>
int main(int ac, char *av[])
{
    (void)ac;
    int i = 1;
    char *storage;
    storage = (char *)calloc(10, sizeof(char));
    while (av[i] != NULL)
    {
        storage = ft_strjoin2(storage, av[i]);
        i++;
    }
    char **tmp = ft_split(storage, ' ');
    int counter = 0;
    i = 0;
    while (tmp[counter])
    {
        counter++;
    }
    i = 0;
    long int *rt;
    rt = malloc(counter * sizeof(long int));
    while (tmp[i])
    {
        rt[i] = ft_atol(tmp[i]);
        i++;
    }
    is_duplicate(rt, i);
    int j = 0;
    t_list **stack_a;
    stack_a = malloc(sizeof(t_list *));
    *stack_a = NULL;
    t_list **stack_b;
    stack_b = malloc(sizeof(t_list *));
    *stack_b = NULL;
    while (j < i)
    {
        t_list *node = ft_lstnew(rt[j]);
        ft_lstadd_back(stack_a, node);
        j++;
    }
    push_top_two(stack_a, stack_b);
    while (ft_lstsize(*stack_a) > 3)
    {
        find_index(stack_a, stack_b);
        find_target(stack_a, stack_b);
        total_cost(stack_a, stack_b);
        t_list *cheaper = find_cheaper(stack_a);
        rotate_a_to_top(stack_a, cheaper->index);
        rotate_b_to_top(stack_b, cheaper->target);
        pb(stack_b, stack_a);
    }
    sort_a_end(stack_a);
    push_back_to_a(stack_a, stack_b);
    t_list *end_value = *stack_a;
    int min_index = 0;
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
