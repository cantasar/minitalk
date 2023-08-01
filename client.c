/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:44:59 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/01 13:23:38 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	ft_putstr_fd(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *s)
{
	int neg;
	int total;

	neg = 1;
	total = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
	{
		if(*s == '-')
			neg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		total = total * 10 + (*s - '0');
		s++;
	}
	return (total * neg);
}

void	send_bit(int pid, char c)
{
    int bit = 0;
	int i = 0;

	while (bit < 32)
	{
		if ((c >> bit) & 1)
		{
			printf("%d) bit = %d, char = %c  -> 1\n", i, c>>bit , c);
			kill(pid, SIGUSR1);
		}
		else
		{
			printf("%d) bit = %d, char = %c  -> 0\n", i, c>>bit , c);
			kill(pid, SIGUSR2);
		}
		usleep(50);
		bit++;
		i++;
	}
}

int main(int argc, char const *argv[])
{
    int pid;
	int i;
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
			send_bit(pid, argv[2][i++]);
		return 0;
	}
	else
		ft_putstr_fd("invalid number of arguments\nUse: ./client <pid> <text>\n");
	return (0);
}
