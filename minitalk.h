/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mintalk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:52:27 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/21 23:08:00 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINTALK_H
#define MINTALK_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

typedef struct s_data
{
    int i;
    char *str;
    int c;

}       t_data;


#endif