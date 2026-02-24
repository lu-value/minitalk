/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:34:57 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/01/20 11:34:58 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	is_valid_pid(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <pid> <message>\n", 2);
		return (1);
	}
	if (!is_valid_pid(argv[1]))
	{
		ft_putstr_fd("Error: invalid PID\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: invalid PID\n", 2);
		return (1);
	}
	if (ft_send_msg(pid, argv[2]) == -1)
	{
		ft_putstr_fd("Error: failed to send message\n", 2);
		return (1);
	}
	return (0);
}
