/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:57:01 by shongou           #+#    #+#             */
/*   Updated: 2022/07/26 22:57:05 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_sig = 0;

void	hoge(void)
{
	static char	c = '\0';
	static int	i = 0;

	c = c << 1;
	if (g_sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == ONE_BYTE)
	{
		write(1, &c, 1);
		i = 0;
		c = '\0';
	}
}

void	handler(int bit)
{
	g_sig = bit;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
		hoge();
	}
	return (0);
}
