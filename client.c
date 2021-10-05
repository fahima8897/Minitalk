/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:08:39 by fboumell          #+#    #+#             */
/*   Updated: 2021/10/05 11:08:42 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
  /*  if (argc != 3)
        return (0);
*/
	int pid;

	pid = getpid();
	printf("Mon PID est : %d", pid);
}