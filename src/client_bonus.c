/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:29:21 by luiribei          #+#    #+#             */
/*   Updated: 2024/11/14 15:34:03 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

static int	g_sign_sent;

void	sig_handler(int sign, siginfo_t *info, void *context)
{
	static int	bits;

	(void)context;
	(void)info;
	(void)sign;
	g_sign_sent = true;
	if (sign == SIGUSR2)
		bits++;
	else if (sign == SIGUSR1)
		ft_printf("Number of bytes received -> %d\n", bits / 8);
}

int	ft_char_to_bin(char c, int pid)
{
	int	i;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		i = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_sign_sent == false)
		{
			if (i == 5)
			{
				ft_putstr_fd("No response from server.\n", 1);
				exit(0);
			}
			i++;
			usleep(10000000);
		}
		g_sign_sent = false;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					byte_index;
	int					pid;

	if (argc != 3)
	{
		ft_printf("You need to pass 2 args but u passed %d\n", argc - 1);
		return (1);
	}
	byte_index = 0;
	pid = ft_atoi(argv[1]);
	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (pid < 0 || kill(pid, 0) == -1)
		return (ft_printf("check your pid \n"));
	if (sigaction(SIGUSR1, &sa, NULL) == -1 \
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_putstr_fd("Error sigaction\n", 1), 1);
	while (argv[2][byte_index])
		ft_char_to_bin(argv[2][byte_index++], pid);
	ft_char_to_bin('\0', pid);
	return (0);
}

/*

Encryption

Client Side:

'A' in ASCII: 65
Binary: 01000001

Send each bit:
•         Bit 7: 0 -> SIGUSR2
•         Bit 6: 1 -> SIGUSR1
•         Bit 5: 0 -> SIGUSR2
•         Bit 4: 0 -> SIGUSR2
•         Bit 3: 0 -> SIGUSR2
•         Bit 2: 0 -> SIGUSR2
•         Bit 1: 0 -> SIGUSR2
•         Bit 0: 1 -> SIGUSR1

*/