#include "push_swap.h"
#include <stdio.h>

long ft_atol(char *s)
{
    int i = 0;
    long result = 0;
    long sign = 1;
    while(s[i] == ' ' || s[i] == '\t')
        i++;
    if(s[i] == '-' || s[i] == '+')
    {
        if(s[i] == '-')
            sign *= -1;
        i++;
    }
	while(s[i] >= '0' && s[i] <= '9')
    {
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			write(2,"Error\n",6);
			exit(1);
		}
        result = (result * 10) + (s[i] - '0');
        i++;
    }
	if ((sign == 1 && result >= 2147483647)
	|| (sign == -1 && result >= 2147483648))
	{
		write(2,"Error\n",6);
        exit(1);
	}
	result = result * sign;
    return (result);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		u;
	int		i;
	char	*ptr;
	int		j;

	u = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	ptr = (char *)malloc((u) * (sizeof(char)) + 2);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
    ptr[i] = ' ';
	ptr[i+1] = '\0';
	return (ptr);
}

