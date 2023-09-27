/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:44:59 by ctasar            #+#    #+#             */
/*   Updated: 2023/09/27 19:28:08 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(const char *s)
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
	int	neg;
	int	total;

	neg = 1;
	total = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
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
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (bit < 32)
	{
		if ((c >> bit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(50);
		bit++;
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		if (argc == 3 && ft_atoi(argv[1]) <= 0)
		{
			ft_error("pid cannot be less or equal 0 !!!\n");
			return (0);
		}
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
			send_bit(pid, argv[2][i++]);
		return (0);
	}
	else
		ft_error("invalid number of arguments\nUse: ./client <pid> <text>\n");
	return (0);
}
