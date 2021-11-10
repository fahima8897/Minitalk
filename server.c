/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:50 by fboumell          #+#    #+#             */
/*   Updated: 2021/10/05 12:10:50 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_my_pid(void)
{
	pid_t pid;

	pid = getpid();
	ft_putstr("Hello my PID is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

int main()
{
	get_my_pid();
}
