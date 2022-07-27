/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 22:56:29 by shongou           #+#    #+#             */
/*   Updated: 2022/07/26 22:56:34 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	check_only_digit(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		if (i >= INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static void	messenger(int pid, char *msg)
{
	int		nbit;
	int		which_bit;
	int		kill_check;
	size_t	i;

	i = 0;
	while (msg[i] != '\0')
	{
		nbit = MAX_RIGHT_SHIFT;
		while (nbit >= 0)
		{
			which_bit = (msg[i] >> nbit) & 1;
			if (which_bit == 1)
				kill_check = kill((pid_t)pid, SIGUSR1);
			if (which_bit == 0)
				kill_check = kill((pid_t)pid, SIGUSR2);
			if (kill_check == -1)
				exit(1);
			usleep(100);
			nbit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*sig;

	if (argc != 3 || check_only_digit(argv[1]) == 0)
		exit(1);
	pid = ft_atoi(argv[1]);
	if ((100 > pid && pid < 99998) || kill(pid, 0) == -1)
		exit(1);
	sig = argv[2];
	messenger(pid, sig);
	return (0);
}
