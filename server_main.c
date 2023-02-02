/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:54 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/02 23:01:08 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	temp = n % 10 + 48;
	write(fd, &temp, 1);
}

void	show_pid(int pid)
{
	write(1, "PID is ", 9);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int pid;

	pid = getpid();
	show_pid(pid);
	return (0);
}