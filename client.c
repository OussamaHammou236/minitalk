/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:47 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/21 23:11:53 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void ft_Decimal_to_Binary(int c, int pid)
{
	int i;

	i	=	0;
	while(i < 8)
	{
		if(c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c>>1;
		i++;
		usleep(50);
	}
}
int main(int ac, char **av)
{
	int pid;
	int i;

	i = 0;
	if (ac < 3)
		return 0;
	pid = ft_atoi(av[1]);

	while(av[2][i])
	{
		ft_Decimal_to_Binary(av[2][i],pid);
		i++;
	}
	return 0;
}