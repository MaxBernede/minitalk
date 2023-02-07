/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 16:11:45 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/07 16:33:17 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./minitalk.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	c;
	size_t	added;

	added = size * nmemb;
	ptr = malloc(sizeof(int) * added);
	if (!ptr)
		return (NULL);
	c = 0;
	while (c < added)
	{
		ptr[c] = '\0';
		++c;
	}
	return ((void *)ptr);
}

char	*maxneg(void)
{
	char	*ptr;

	ptr = (char *)malloc(12);
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, "-2147483648", 12);
	return (ptr);
}

char	*coppy(char *ptr, int div, int n, int t)
{
	while (div > 0)
	{
		ptr[div + t - 1] = n % 10 + 48;
		n /= 10;
		--div;
	}
	return (ptr);
}

char	*allooc(int n, int div)
{
	char	*ptr;

	if (n < 0)
		div += 2;
	else
		++div;
	ptr = ft_calloc(div, 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		div;
	int		t;

	div = 1;
	t = n;
	if (n == -2147483648)
		return (maxneg());
	while ((t > 9 || t < -9))
	{
		t /= 10;
		++div;
	}
	ptr = allooc(n, div);
	if (!ptr)
		return (NULL);
	t = 0;
	if (n < 0)
		t = 1;
	if (n < 0)
		n *= -1;
	ptr = coppy(ptr, div, n, t);
	return (ptr);
}
