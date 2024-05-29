/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:39:01 by agiraud           #+#    #+#             */
/*   Updated: 2021/09/28 11:32:44 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	sig_handler(int sig)
{
	static char	c = 0;
	static int	bit_number = -1;

	bit_number++;
	if (sig == SIGUSR1)
		c = (c << 1);
	if (sig == SIGUSR2)
		c = (c << 1) | 1;
	if (bit_number == 7)
	{
		ft_printf("%c", c);
		c = 0;
		bit_number = -1;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("The server pid is %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
