/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/05 22:05:24 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./minitalk.h"

int binary;

void	show_pid(int pid)
{
	write(1, "PID is ", 8);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

void	handle_1(int sig, siginfo_t *siginfo, void *context)
{
	binary = 1;
	//kill(siginfo->si_pid, SIGUSR1);
}

void	handle_2(int sig, siginfo_t *siginfo, void *context)
{
	binary = 0;
	//kill(siginfo->si_pid, SIGUSR1);
}

int	divnb(int div, int i)
{
	if (i == 0)
		div = 128;
	else
		div /= 2;
	return (div);
}

void	valinit(t_ser_val *s_val)
{
	s_val->cli_pid = 0;
	s_val->pid = getpid();
	s_val->div = divnb(s_val->div, 0);
}

int main(int argc, char **argv)
{

	int c;
	int i;
	struct sigaction sa1;
	struct sigaction sa2;
	t_ser_val	s_val;

	valinit(&s_val);
	sa1.sa_sigaction = handle_1;
	sa2.sa_sigaction = handle_2;
	sa1.sa_flags = SA_SIGINFO;
	sa2.sa_flags = SA_SIGINFO;
	i = 0;
	c = 0;
	show_pid(s_val.pid);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
	{
		pause();
		++i;
		if (i < 8)
		{
			if (binary)
				c += s_val.div;
		}
		else
		{
			if (binary)
				c += 1;
			write(1, &c, 1);
			i = 0;
			c = 0;
		}
		s_val.div = divnb(s_val.div, i);
	}
	return (0);
}
