/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/07 19:15:17 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./minitalk.h"
#include <stdlib.h>

int	g_binary;

void	f_sig1()
{
	g_binary = 1;
}

void	f_sig2()
{
	g_binary = 0;
}

void	show_pid(int pid)
{
	write(1, "PID is ", 9);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

int	divnb(int div, int i)
{
	if (i == 0)
		div = 128;
	else
		div /= 2;
	return (div);
}

void	check_pid(int *i, int *c, int *div, t_pid *pids)
{
	++(*i);
	if (*i < 8)
	{
		if (g_binary)
			*c += *div;
	}
	else
	{
		if (g_binary)
			*c += 1;
		if (!(*c))
		{
			pids->int_cli_pid = ft_atoi(pids->cli_pid);
			//printf("PID SENDER : %d\n", pids->int_cli_pid);
		}
		else
		{
			pids->cli_pid[pids->x] = *c;
			pids->x += 1;
		}
		*i = 0;
		*c = 0;
	}
	*div = divnb(*div, *i);
}

void	fill0(t_pid *pids)
{
	int i;

	i = 0;
	while (i < 8)
	{
		pids->cli_pid[i] = '\0';
		++i;
	}
	pids->int_cli_pid = 0;
	pids->x = 0;
}

void	check(int *i, int *c, int *div, t_pid *pids)
{
	++(*i);
	if (*i < 8)
	{
		if (g_binary)
			*c += *div;
	}
	else
	{
		if (g_binary)
			*c += 1;
		if (*c == '\n')
		{
			write(1, c, 1);
			kill(pids->int_cli_pid, SIGUSR2);
			fill0(pids);
		}
		else
			write(1, c, 1);
		*i = 0;
		*c = 0;
	}
	*div = divnb(*div, *i);
	if (pids->int_cli_pid)
		kill(pids->int_cli_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	c;
	int	i;
	int	div;
	t_pid	pids;

	i = 0;
	c = 0;
	div = 128;
	pids.int_cli_pid = 0;
	pids.x = 0;
	pids.cli_pid = ft_calloc(1, 8);
	pid = getpid();
	show_pid(pid);
	signal(SIGUSR1, f_sig1);
	signal(SIGUSR2, f_sig2);
	while (1)
	{
		pause();
		if (!(pids.int_cli_pid))
			check_pid(&i, &c, &div, &pids);
		else
			check(&i, &c, &div, &pids);
	}
	return (free(pids.cli_pid), 0);
}
