/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:16:24 by ctasar            #+#    #+#             */
/*   Updated: 2023/08/01 14:29:56 by ctasar           ###   ########.fr       */
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

void signal_handler(int signal)
{
	static char				bit = 0;
	static unsigned char	i = 0;

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

int main(void)
{
    printf("PID = %d\n", getpid());

    while (1)
    {
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
        pause();
    }
    return 0;
}
