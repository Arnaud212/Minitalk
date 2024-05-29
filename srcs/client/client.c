/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:38:51 by agiraud           #+#    #+#             */
/*   Updated: 2021/09/28 11:28:51 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	error_msg(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	send_char(char c, int pid)
{
	int		i;
	char	bit;

	i = 7;
	while (i > -1)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_msg("Unvalid Pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_msg("Unvalid Pid\n");
		}
		usleep(600);
		i--;
	}
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid_server;

	if (ac != 3)
		error_msg("Usage :./client <pid_server> <string_to_pass>\n");
	pid_server = ft_atoi(av[1]);
	if (pid_server == 0)
		error_msg("Unvalid Pid\n");
	if (!check_pid(av[1]))
		error_msg("Unvalid Pid\n");
	i = 0;
	while (av[2][i])
	{
		send_char(av[2][i], pid_server);
		i++;
	}
	return (0);
}
