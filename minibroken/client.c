/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:53 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/07 19:00:25 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int	g_binary;

void	f_sig1()
{
	g_binary = 1;
}

void	f_sig2()
{
	printf("received\n");
	g_binary = -1;
}

void	messagepid(int pid, char *str, int i, int b)
{
	while (str[i])
	{
		b = 8;
		while (b--)
		{
			if (str[i] >> b & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_binary != 1)
			{
				if (g_binary == -1)
				{
					g_binary = 0;
					exit(0);
				}
			}
			g_binary = 0;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	mypid;

	if (argc != 3)
		return (ft_error());
	pid = ft_atoi_overflow(argv[1]);
	if (!pid)
		return (ft_error());
	mypid = getpid();
	i = sendpid(pid, mypid);
	signal(SIGUSR1, f_sig1);
	signal(SIGUSR2, f_sig2);
	messagepid(pid, argv[2], 0, 8);
	messagepid(pid, "\n", 0, 8);

	return (0);
}
