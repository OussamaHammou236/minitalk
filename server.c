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



void test(int signo)
{
	if(signo == SIGUSR1)
		printf("1");
	if(signo == SIGUSR2)
		printf("0");
	printf("\n");
}
int main()
{
	int	i;
	struct sigaction psa;

	psa.sa_handler = test;
	psa.sa_flags = 0;
	i = getpid();
	printf("%d\n", i);
	while(1)
	{
		sigaction(SIGUSR1, &psa, NULL);
		sigaction(SIGUSR2, &psa, NULL);
	}
}