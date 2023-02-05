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

unsigned int binary;

void	show_pid(int pid)
{
	write(1, "PID is ", 9);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

void	f_sig1()
{
	binary = 1;
}

void	f_sig2()
{
	binary = 0;
}

int main(int argc, char **argv)
{
	int pid;
	unsigned int c;
	unsigned int i;
	unsigned int div;

	i = 0;
	c = 0;
	pid = getpid();
	show_pid(pid);
	signal(SIGUSR1, f_sig1);
	signal(SIGUSR2, f_sig2);

	div = 128;
	while (1)
	{
		pause();
		++i;
		if (i < 8)
		{
			if (binary)
				c += div;
		}
		else
		{
			if (binary)
				c += 1;
			write(1, &c, 1);
			i = 0;
			c = 0;
		}
		if (i == 0)
			div = 128;
		else
			div /= 2;
	}
	return (0);
}




//	struct sigaction sa;

	// sa.sa_handler = &handle;
	// sigaction(SIGTSTP, &sa, NULL);