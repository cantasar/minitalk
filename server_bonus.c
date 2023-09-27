/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:16:24 by ctasar            #+#    #+#             */
/*   Updated: 2023/09/27 19:08:04 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	signal_handler(int signal)
{
	static unsigned char		i;
	static char					bit;

	if (signal == SIGUSR1)
		i += (1 << bit);
	bit++;
	if (bit == 32)
	{
		write(1, &i, 1);
		i = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("PID = %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
