/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mintalk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:27 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/14 01:06:57 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINTALK_H
#define MINTALK_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

typedef struct s_data
{
    int i;
    char *str;
    int c;

}       t_data;


#endif