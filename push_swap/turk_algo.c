#include "push_swap.h"
#include <stdio.h>

int find_cost(t_list *stack, int target_index) // bu fonksiyonu a'dan b'ye atarken her eleman için çağırırız
{
    int cost;
    int number_of_nodes = ft_lstsize(stack);
    if (target_index <= number_of_nodes / 2)
        cost = target_index;
    else
        cost = number_of_nodes - target_index;
    return cost;
}

void push_top_two(t_list **stack_a, t_list **stack_b)
{
    pb(stack_b, stack_a);
    pb(stack_b, stack_a);
}

int find_max(t_list **stack_b)
{
    int max = (*stack_b)->data;
    t_list *temp = *stack_b;
    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

int find_min(t_list **stack_b)
{
    int min = (*stack_b)->data;
    t_list *temp = *stack_b;
    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;

        temp = temp->next;
    }
    return min;
}

void find_index(t_list **stack_a, t_list **stack_b)
{
    t_list *temp1 = *stack_a;
    t_list *temp2 = *stack_b;
    int i = 0;
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

void find_target(t_list **stack_a, t_list **stack_b) // stackb de gelecek konumun indexini döndürür
{
    // stacka daki her eleman için stackb ye gelirse hangi indexe gelir bunu bul.
    t_list *temp_a = *stack_a;
    t_list *temp_b;
    int bigger;          // negatif sayılar da verilebildiği için.
    while (temp_a != NULL) // stacka daki her bir eleman için
    {
        temp_b = *stack_b; // her a daki eleman için stack_b nin başından bakmaya başlasın diye.
        int target = 0;
        bigger = INT_MIN;
        while (temp_b != NULL)
        {
            if (temp_a->data > find_max(stack_b) || temp_a -> data < find_min(stack_b))
            {
                
                int max = find_max(stack_b);
                t_list *temp = *stack_b;
                int max_index = 0;
                while (temp != NULL)
                {
                    
                    if (temp->data == max)
                    {
                        
                        max_index = temp->index;
                        break;
                    }
                    temp = temp->next;
                }
                target = max_index;
            }
            if (temp_a->data > temp_b->data && temp_a->data > bigger)
            {
                bigger = temp_b->data;
                target = temp_b->index;
            }
            temp_b = temp_b->next;
        }
        temp_a->target = target;
        temp_a = temp_a->next;

    }
}

void find_target_a(t_list **stack_a, t_list **stack_b) // stackb de gelecek konumun indexini döndürür
{
    // stacka daki her eleman için stackb ye gelirse hangi indexe gelir bunu bul.
    t_list *temp_b = *stack_b;
    t_list *temp_a;
    int smaller;          // negatif sayılar da verilebildiği için.
    while (temp_b != NULL) // stacka daki her bir eleman için
    {
        temp_a = *stack_a; // her a daki eleman için stack_b nin başından bakmaya başlasın diye.
        int target = 0;
        smaller = INT_MAX;
        int min_index = 0;
        while (temp_a != NULL)
        {
            if (temp_b->data > find_max(stack_a) || temp_b->data < find_min(stack_a))
            {
                int min = find_min(stack_a);
                t_list *temp_a = *stack_a;
                
                while (temp_a != NULL)
                {
                    if (temp_a->data == min)
                    {
                        min_index = temp_a->index;
                        break;
                    }
                    temp_a = temp_a->next;
                }
                target = min_index;
            }
            
            if ((temp_b->data < temp_a->data) && (temp_a->data < smaller))
            {
                smaller = temp_a->data;
                target = temp_a->index;
            }
            temp_a = temp_a->next;
        }
        //printf("target data: %d\n", bigger);
        temp_b->target = target;
        temp_b = temp_b->next;
    }
}

void total_cost(t_list **stack_a, t_list **stack_b)
{
    t_list *temp = *stack_a;
    while (temp != NULL)
    {
        int cost1 = find_cost(*stack_a, temp->index);
        int cost2 = find_cost(*stack_b, temp->target);
        temp->cost = cost1 + cost2;
        temp = temp->next;
    }
}

t_list *find_cheaper(t_list **stack_a)
{
    if (!stack_a)
        return NULL;
    t_list *temp = *stack_a;
    int min_cost = INT_MAX;
    t_list *cheaper = temp;
    while (temp != NULL)
    {
        if (temp->cost < min_cost || (temp->cost == min_cost && temp->index < cheaper->index))
        {
            min_cost = temp->cost;
            cheaper = temp;
        }
        temp = temp->next;
    }
    return cheaper;
}

void rotate_a_to_top(t_list **stack_a, int index)
{
    int s_size = ft_lstsize(*stack_a);
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
        int reverse = s_size - index;
        while (reverse > 0)
        {
            rra(stack_a);
            reverse--;
        }
    }
}

void rotate_b_to_top(t_list **stack_b, int target)
{
    int s_size = ft_lstsize(*stack_b);
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
        int reverse = s_size - target;
        while (reverse > 0)
        {
            rrb(stack_b);
            reverse--;
        }
    }
}

void sort_a_end(t_list **stack_a)
{
    if (((*stack_a)->next->data) < ((*stack_a)->data))
        sa(stack_a);                                  

    if ((*stack_a)->next->next->data < (*stack_a)->data) 
    {
        rra(stack_a);
    }
    if ((*stack_a)->next->data > (*stack_a)->next->next->data) 
    {
        sa(stack_a);
        ra(stack_a);
    }
}

void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
   while (ft_lstsize(*stack_b) > 0)
    {
        find_index(stack_a, stack_b);
        find_target_a(stack_a, stack_b);
        total_cost(stack_b, stack_a);
        t_list *cheaper = find_cheaper(stack_b);
        rotate_a_to_top(stack_a, cheaper->target);
        rotate_b_to_top(stack_b, cheaper->index);
        pa(stack_a, stack_b);
    }
}
