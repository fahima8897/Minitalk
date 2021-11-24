/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:23:46 by marvin            #+#    #+#             */
/*   Updated: 2021/11/24 13:34:12 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

	/* utils.c */
void	ft_putchar(char c);
char	*ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);

	/* clients.c */
int		check_first_argument(char *pid);
void	send_signal(pid_t pid, char c);

	/* server.c */
void	get_my_pid(void);
void	handler(int signum);

#endif