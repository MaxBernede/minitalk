/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   com.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 17:17:41 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/07 18:20:41 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	neg;

	number = 0;
	i = 0;
	neg = 1;
	if (str[i] == 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		++i;
	}
	return (number * neg);
}

void	message(int pid, char *str, int i, int b)
{
	usleep(500);
	while (str[i])
	{
		b = 8;
		while (b--)
		{
			if (str[i] >> b & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(400);
		}
		++i;
	}
}

int	sendpid(int pid, int mypid)
{
	char    *strpid;
    int     i;

	strpid = ft_itoa(mypid);
	message(pid, strpid, 0, 8);
    i = 0;
	while (i < 8)
    {
        kill(pid, SIGUSR2);
        ++i;
        usleep(400);
    }
	return (0);
}
