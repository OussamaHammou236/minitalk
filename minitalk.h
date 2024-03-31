/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:27 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/31 00:11:13 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_atoi(const char *str);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_data
{
	int		i;
	char	*str;
	int		c;

}			t_data;

#endif