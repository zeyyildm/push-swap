#include "push_swap.h"

 t_list *ft_lstnew(long content)
{
    t_list *newNode = (t_list *)(malloc(sizeof(t_list)));
    if(!newNode)
        return NULL;
    newNode -> data = content;
    newNode -> next = NULL;
    return newNode;
} 

void ft_lstadd_front(t_list **lst, t_list *new)
{
    t_list *tmp = (*lst);
    (*lst) = new;
    new ->next = tmp;
}

void pop(t_list **head)
{
    t_list *tmp = *head;
    (*head) = tmp -> next;
    tmp -> next = NULL;
}

int ft_lstsize(t_list *lst)
{
    int counter = 0;
    while(lst != NULL)
    {
        counter++;
        lst = lst -> next;
    }
    return counter;
}


void sa(t_list **lst)
{
    if(*lst == NULL || (*lst)->next==NULL)
        return;
    t_list *temp = *lst;

    t_list *temp2 = (*lst) -> next; 
    
    (*lst) = (*lst) -> next; 

    (*lst) ->  next = temp; 

    temp -> next =  temp2 -> next;

}


void sb(t_list **lst)
{
    if(*lst == NULL || (*lst)->next==NULL)
        return;
    t_list *temp = *lst;

    t_list *temp2 = (*lst) -> next;
    
    (*lst) = (*lst) -> next;

    (*lst) ->  next = temp;

    temp -> next =  temp2 -> next;
}

void ss(t_list **lst_a, t_list **lst_b)
{
    sa(lst_a);
    sb(lst_b);
}

 void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *head = (*stack_b);
    pop(stack_b);
    ft_lstadd_front(stack_a, head);
}

 void pb(t_list **stack_b, t_list **stack_a)
{
    t_list *head = (*stack_a);
    pop(stack_a);
    ft_lstadd_front(stack_b, head);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;
    if(*lst == NULL)
        *lst = new;  
    else 
    {
        temp = *lst;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = new;
    }
}

void ra(t_list **stack_a)
{
    t_list *head = (*stack_a);
    pop(stack_a);
    ft_lstadd_back(stack_a, head);
}

void rb(t_list **stack_b)
{
    t_list *head = (*stack_b);
    pop(stack_b);
    ft_lstadd_back(stack_b, head);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(t_list **stack_a)
{
    t_list *temp = *stack_a;
    while(temp->next->next != NULL)
    {
        temp = temp -> next;
    }
    t_list *temp2= temp->next;
    temp -> next = NULL;
    ft_lstadd_front(stack_a,temp2);
}

void rrb(t_list **stack_b)
{
     t_list *temp = *stack_b;
    while(temp->next->next != NULL)
    {
        temp = temp -> next;
    }
    t_list *temp2= temp->next;
    temp -> next = NULL;
    ft_lstadd_front(stack_b,temp2);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}