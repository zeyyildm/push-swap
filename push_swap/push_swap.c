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
        storage = ft_strjoin2(storage,av[i]);
        i++;
    }
    char **tmp = ft_split(storage, ' ');
    int counter = 0;
    i = 0;
    while(tmp[counter])
    {
        counter++;
    }
    i = 0;
    long int *rt;
    rt = malloc(counter * sizeof(long int));
    while(tmp[i])
    {
        rt[i] = ft_atol(tmp[i]);
        i++;
    }
    is_duplicate(rt,i);
    int j = 0;
    t_list **stack_a;
    stack_a = malloc(sizeof(t_list *));
    *stack_a = NULL;
    t_list **stack_b;
    stack_b = malloc(sizeof(t_list *));
    *stack_b = NULL;
    while(j < i)
    {
        t_list *node = ft_lstnew(rt[j]);
        ft_lstadd_back(stack_a,node);
        j++;
    }
    push_top_two(stack_a,stack_b);
    while(ft_lstsize(*stack_a) > 3) 
    {
       find_index(stack_a, stack_b);
       find_target(stack_a, stack_b);
       total_cost(stack_a, stack_b);
       t_list *cheaper = find_cheaper(stack_a);
       int data = cheaper -> data;
       printf("bu sayı pushlandı: %d\n", data);
       if(data > find_max(stack_b) || data < find_min(stack_b))
       {
            rotate_a_to_top(stack_a, cheaper -> index);
            int max = find_max(stack_b);
            t_list *temp = *stack_b;
            int max_index = 0;
            while(temp != NULL)
            {
                if(temp -> data == max)
                {
                    max_index = temp -> index;
                    break;
                }
                temp = temp -> next;
            }
            rotate_b_to_top(stack_b,max_index);
            pb(stack_b,stack_a);
       }
       else
       {
        rotate_a_to_top(stack_a, cheaper->index);
        pb(stack_b, stack_a);
       }
       t_list *temp5 = *stack_a;
        printf("A STACK SON HALİ:");
        printf("\n");
        while(temp5 != NULL)
        {
            printf("%d\n", temp5->data);
            temp5 = temp5 -> next;
        }
        t_list *temp6 = *stack_b;
        printf("\n");
        printf("B STACK SON HALİ:");
        printf("\n");
        while(temp6 != NULL)
        {
            printf("%d\n", temp6->data);
            temp6 = temp6 -> next;
        }
    }
    //bu while dan çıkınca sadece 3 tane kalmış olacak
    sort_a_end(stack_a); //sorun var 6-8-8 yazdırıyor
    t_list *temp9 = *stack_a;
    printf("A:%d\n", temp9->data);
    printf("%d\n", temp9->next->data);
    printf("A:%d", temp9->next->next->data);

}

    
