/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:35:24 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/01/20 11:35:25 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile sig_atomic_t	g_ack = 0;

static void	ack_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	g_ack = 1;
}

static int	get_bit(char c, int pos)
{
	return ((c >> pos) & 1);
}

static int	send_bit(int pid, int bit)
{
	g_ack = 0;
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (-1);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			return (-1);
	}
	while (!g_ack)
		pause();
	return (0);
}

static int	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (send_bit(pid, get_bit(c, bit)) == -1)
			return (-1);
		bit++;
	}
	return (0);
}

int	ft_send_msg(int pid, char *msg)
{
	struct sigaction	sa;
	int					i;

	sa.sa_sigaction = ack_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (msg[i])
	{
		if (send_char(pid, msg[i]) == -1)
			return (-1);
		i++;
	}
	if (send_char(pid, '\0') == -1)
		return (-1);
	return (0);
}
