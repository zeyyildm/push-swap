/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:57:18 by zeyildir          #+#    #+#             */
/*   Updated: 2025/10/22 18:10:36 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	if ((sign == 1 && result >= 2147483647) || (sign == -1
			&& result >= 2147483648))
	{
		write(2, "Error\n", 6);
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

	if (!s1 || !s2)
		return (NULL);
	u = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	ptr = (char *)malloc((u + 2) * sizeof(char));
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
	ptr[i + 1] = '\0';
	return (ptr);
}
