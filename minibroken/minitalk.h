/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:50:39 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/07 18:21:01 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

typedef struct s_pid
{
	char	*cli_pid;
	int		int_cli_pid;
	int		x;
} t_pid;


void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi_overflow(char *str);
int		ft_error(void);
void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);

int		ft_atoi(const char *str);
void	message(int pid, char *str, int i, int b);
int		sendpid(int pid, int mypid);

#endif