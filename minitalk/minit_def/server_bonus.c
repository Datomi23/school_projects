/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi < dadeyemi@student.42firenze.i    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:29:29 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/08/22 09:29:29 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	go(int signum, siginfo_t *info, void *ucontext)
{
	static int	c_bit;
	static char	c;

	(void)ucontext;
	if (c_bit < 8)
	{
		c = c << 1;
		if (signum == SIGUSR2)
			c++;
		c_bit++;
	}
	if (c_bit >= 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		c = 0;
		c_bit = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("Server Process ID: %d\n", getpid());
	sigemptyset(&s_action.sa_mask);
	sigaddset(&s_action.sa_mask, SIGUSR1);
	sigaddset(&s_action.sa_mask, SIGUSR2);
	s_action.sa_flags = SA_SIGINFO | SA_NODEFER;
	s_action.sa_sigaction = go;
	sigaction(SIGUSR1, &s_action, 0);
	sigaction(SIGUSR2, &s_action, 0);
	while (1)
		pause();
	return (0);
}
