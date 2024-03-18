/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:53:47 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/15 14:35:12 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mintalk.h"

void charToBinary(char c,int b) 
{
    int asciiValue = (int)c;
    int mask = 1 << 7; 
	int i = 0;
	
    while(i < 8)
	{

        if (asciiValue & mask)
            kill(b,SIGUSR1); 
		else 
            kill(b,SIGUSR2);
        mask >>= 1;
		usleep(50);
		i++;
    }
}

int main(int ac, char **av)
{
	int	i;
	int c;
	
	c = 0;
	if(ac <= 2)
		return 0;
	i = ft_atoi(av[1]);
	while(av[2][c])
	{
		charToBinary(av[2][c],i);
		printf("%c\n",av[2][c]);
		c++;
	}
	
	return 0;
}