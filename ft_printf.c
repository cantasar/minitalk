/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctasar <ctasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:25:35 by ctasar            #+#    #+#             */
/*   Updated: 2023/09/27 19:09:26 by ctasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	arg_check(va_list lst, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(lst, int));
	else if (c == 'd')
		ft_putnbr(va_arg(lst, int));
	else if (c == 's')
		ft_putstr(va_arg(lst, char *));
}

void	ft_printf(const char *str, ...)
{
	int		i;
	va_list	lst;

	i = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			arg_check(lst, str[i + 1]);
			i += 2;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(lst);
}
