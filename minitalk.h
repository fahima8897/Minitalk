/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:23:46 by marvin            #+#    #+#             */
/*   Updated: 2021/11/04 14:23:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

        /* utils.c */
void    ft_putchar(char c);
char    ft_putstr(char *str);
void    ft_putnbr(int n);
int     ft_atoi(const char *str);

#endif