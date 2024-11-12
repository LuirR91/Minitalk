/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:50:03 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/12 17:00:51 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_bin_to_char(int signal, char *c)
{
	if (signal == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signal == SIGUSR2)
		*c <<= 1;
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int		pid;
	static char		c;
	static int		bits;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	ft_bin_to_char(signal, &c);
	if (++bits == 8)
	{
		bits = 0;
		if (c == '\0')
		{
			kill(pid, SIGUSR1);
			pid = 0;
			return ;
		}
		write (1, &c, 1);
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome To Luis' Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_putstr_fd("Error sigaction\n", 1);
	while (1)
		pause();
	return (0);
}
