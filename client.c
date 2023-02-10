/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:53 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/05 22:06:52 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
#include <stdio.h>

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

int main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (ft_error());
	pid = ft_atoi_overflow(argv[1]);
	if (!pid)
		return (ft_error());
	message(pid, argv[2], 0, 8);
	message(pid, "\n", 0, 8);
	return (0);
}
