#include "push_swap.h"
#include <stdio.h>

void is_duplicate(long *n, int counter)
{
    int i = 0;
    int j;
    while(i <= counter)
    {
        j = i + 1;
        while(j <= counter)
        {
            if(n[i] == n[j])
            {
                write(2, "Error\n",6);
                exit(1);
            }
            j++;
        }
        i++;
    }
}
