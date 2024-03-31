/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:12:35 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/31 00:09:25 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_data	g_data;

int	os(int nb, int n)
{
	int	c;

	c = 1;
	while (n > 0)
	{
		c *= nb;
		n--;
	}
	return (c);
}

void	test(int signo, siginfo_t *act, void *octat)
{
	octat = NULL;
	if (signo == SIGUSR1)
		g_data.c += os(2, 7 - g_data.i);
	if (g_data.i == 0)
	{
		write(1, &g_data.c, 1);
		if (g_data.c == '\0')
		{
			write(1, "\n", 1);
			kill(act->si_pid, SIGUSR1);
		}
		g_data.c = 0;
		g_data.i = 7;
		return ;
	}
	g_data.i--;
}

int	main(void)
{
	int					i;
	struct sigaction	psa;

	psa.sa_flags = SA_SIGINFO;
	psa.sa_sigaction = test;
	i = getpid();
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
	g_data.i = 7;
	g_data.c = 0;
	sigaction(SIGUSR1, &psa, NULL);
	sigaction(SIGUSR2, &psa, NULL);
	while (1)
		;
}
