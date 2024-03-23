/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:12:35 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/21 23:13:53 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

t_data data;

int os(int nb, int n)
{
	int c;

	c = 1;
	while(n > 0)
	{
		c *= nb;
		n--;
	}

	return c;
}
void test(int signo, siginfo_t *act, void *octat)
{
	if(signo == SIGUSR1)
	{
		data.str[data.i] = '1';
		data.c += os(2, 7 - data.i);
	}
	else if(signo == SIGUSR2)
		data.str[data.i] = '0';
	if(data.i == 0)
	{
		write(1,&data.c,1);
		if(data.c == '\0')
			kill(act->si_pid,SIGUSR1);
		data.c = 0;
		data.i = 7;
		return ;
	}
	data.i--;
}
int main()
{
	int	i;
	struct sigaction psa;

	psa.sa_flags = SA_SIGINFO;
	psa.sa_sigaction = test;
	i = getpid();
	printf("%d\n", i);
	data.str = malloc(9);
	data.i = 7;
	data.str[8] = '\0';
	data.c = 0;
	sigaction(SIGUSR1, &psa, NULL);
	sigaction(SIGUSR2, &psa, NULL);
	while(1)
	{
	}
}