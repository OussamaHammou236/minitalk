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

void test(int signo)
{
	if(signo == SIGUSR1)
		data.str[data.i] = '1';
	else if(signo == SIGUSR2)
		data.str[data.i] = '0';
	data.i++;
	if(data.i == 8)
	{
		data.str[data.i] = '\0';
		printf("%s\n", data.str);
		ft_bzero(data.str, data.i);
		data.i = 0;
		return ;
	}
}
int main()
{
	int	i;
	struct sigaction psa;

	psa.sa_handler = test;
	psa.sa_flags = 0;
	i = getpid();
	printf("%d\n", i);
	data.i = 0;
	data.str = malloc(9);
	while(1)
	{
		sigaction(SIGUSR1, &psa, NULL);
		sigaction(SIGUSR2, &psa, NULL);
	}
}