#include "push_swap.h"
#include <stdio.h>

int find_cost(t_list *stack,int target_index) //bu fonksiyonu a'dan b'ye atarken her eleman için çağırırız
{
    int cost;
    int number_of_nodes = ft_lstsize(stack);
    if(target_index <= number_of_nodes / 2)
        cost = target_index;
    else
        cost = number_of_nodes - target_index;
    return cost;
}

void push_top_two(t_list **stack_a, t_list **stack_b)
{
    pb(stack_b, stack_a);
    pb(stack_b,stack_a);
}

int find_max(t_list **stack_b)
{
    int max = (*stack_b) -> data;
    t_list *temp = *stack_b;
    while(temp != NULL)
    {
        if(temp->data > max)
            max = temp->data;
        temp = temp -> next;
    }
    return max;
}

int find_min(t_list **stack_b)
{
    int min = (*stack_b) -> data;
    t_list *temp = *stack_b;
    while(temp != NULL)
    {
        if(temp->data < min)
            min = temp->data;
    
        temp = temp -> next;
    }
    return min;
}

void find_index(t_list **stack_a, t_list **stack_b)
{
    t_list *temp1 = *stack_a;
    t_list *temp2 = *stack_b;
    int i = 0;
    while(temp1 != NULL)
    {
        temp1 -> index = i;
        temp1 = temp1 -> next;
        i++; 
    }
    i = 0;
    while(temp2 != NULL)
    {
        temp2 -> index = i;
        temp2 = temp2 -> next;
        i++;
    }
}

void find_target(t_list **stack_a, t_list **stack_b)      //stackb de gelecek konumun indexini döndürür                                                                                        
{
       //stacka daki her eleman için stackb ye gelirse hangi indexe gelir bunu bul.
       t_list *temp = *stack_a;
       t_list *temp2 = *stack_b;
       int bigger = INT_MIN; //negatif sayılar da verilebildiği için.
       while(temp != NULL) //stacka daki her bir eleman için
       {
            temp2 = *stack_b; //her a daki eleman için stack_b nin başından bakmaya başlasın diye.
            int target = 0;   
            while(temp2 != NULL)
            {
                if(temp->data > temp2->data && temp2->data > bigger)
                {
                    bigger = temp2 ->data;
                    target = temp2->index;
                }
                temp2 = temp2->next;
            }
            temp->target = target;
            temp = temp->next;
       }
}

void total_cost(t_list **stack_a, t_list **stack_b)
{
    t_list *temp = *stack_a;
    while(temp != NULL)
    {
        int cost1 = find_cost(*stack_a, temp -> index);
        int cost2 = find_cost(*stack_b, temp -> target);
        printf("cost1: %d\n",cost1);
        printf("cost 2: %d\n",cost2);
        temp -> cost = cost1 + cost2;
        temp = temp -> next;
    }
}

t_list *find_cheaper(t_list **stack_a)
{
    if(!stack_a)
        return NULL;
    t_list *temp = *stack_a;
    int min_cost = INT_MAX;
    t_list *cheaper = temp;
    while(temp != NULL)
    {
        if(temp -> cost < min_cost || (temp -> cost == min_cost && temp -> index < cheaper -> index))
        {
            min_cost = temp -> cost;
            cheaper = temp;
        }
        temp = temp -> next;
    }
    return cheaper;
}

void rotate_a_to_top(t_list **stack_a, int index)
{
    int s_size = ft_lstsize(*stack_a);
    if(index <= s_size / 2)
    {
        while(index > 0)
        {
            ra(stack_a);
            index--;
        }
    }
    else
    {
        int reverse = s_size - index;
        while(reverse > 0)
        {
            rra(stack_a);
            reverse--;
        }
    }
}

void rotate_b_to_top(t_list **stack_b, int target)
{
    int s_size = ft_lstsize(*stack_b);
    if(target <= s_size / 2)
    {
        while(target > 0)
        {
            rb(stack_b);
            target--;
        }
    }
    else
    {
        int reverse = s_size - target;
        while(reverse > 0)
        {
            rrb(stack_b);
            reverse--;
        }
    }
}

void sort_a_end(t_list **stack_a)
{
    if(((*stack_a) -> next -> data) < ((*stack_a) -> data)) //2.si 1.snden küçükse
        sa(stack_a); // 2 ile 1 i değiştirdik
    if((*stack_a) -> next -> next -> data < (*stack_a) -> data) //3 ile 1
    {
        ra(stack_a);
        sa(stack_a);
        rra(stack_a);
    }
    if((*stack_a) -> next -> data > (*stack_a) -> next -> next -> data) //min tepeye alındı kalan 2 ye bakıldı
    {
        sa(stack_a);
        ra(stack_a);
    }
}


