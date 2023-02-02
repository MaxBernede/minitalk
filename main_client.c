/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_client.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 22:46:53 by mbernede      #+#    #+#                 */
/*   Updated: 2023/02/02 22:59:14 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		++i;
	}
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1,)
        return (0);
    }
    return (0);
}