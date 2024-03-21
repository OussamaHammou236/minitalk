/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:07 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/15 00:09:03 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mintalk.h"

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

void Binary_to_Decimal()
{
	int c;
	int i;

	i = 0;
	c = 0;
}
void test(int signo)
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

	psa.sa_handler = test;
	psa.sa_flags = 0;
	i = getpid();
	printf("%d\n", i);
	data.str = malloc(9);
	data.i = 7;
	data.str[8] = '\0';
	data.c = 0;
	while(1)
	{
		sigaction(SIGUSR1, &psa, NULL);
		sigaction(SIGUSR2, &psa, NULL);
	}
}