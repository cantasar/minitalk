/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:44:59 by ctasar            #+#    #+#             */
/*   Updated: 2023/07/29 12:23:27 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	send_bit(int pid, char c)
{
    int bit = 0;

	while (bit < 8)
	{
		if (1 & (c >> bit))
		{
			printf("bit = %d, argv[2][i] = %c  -> 1\n", c>>bit , c);
			kill(pid, SIGUSR1);
		}
		else
		{
			printf("bit = %d, argv[2][i] = %c  -> 0\n", c>>bit , c);
			kill(pid, SIGUSR2);
		}
		usleep(500);
		bit++;
	}
}

int main(int argc, char const *argv[])
{
    int pid;
	int i;
	(void)argc;

    printf("PID = %d\n", getpid());
    pid = atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		send_bit(pid, argv[2][i++]);
    return 0;
}
