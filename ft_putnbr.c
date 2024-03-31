/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 23:48:30 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/30 23:58:51 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	long int	l;

	i = 0;
	l = n;
	if (fd < 0)
		return ;
	if (l < 0)
	{
		write(fd, "-", 1);
		l *= -1;
	}
	if (l >= 10)
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd(l % 10 + '0', fd);
	}
	if (l >= 0 && l < 10)
		ft_putchar_fd(l + '0', fd);
}
