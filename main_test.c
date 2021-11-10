#include <unistd.h>
#include <sys/types.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char    *ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    return (str);
}
/*
void    ft_putnbr(int n)
{
    long long c;

    c = n;
    if (c < 0)
    {
        c = -c;
        ft_putchar('-');
    }
    if (c >= 0 && c < 9)
        ft_putchar(c + 48);
    if (c > 9)
    {
        ft_putnbr(c / 10);
        ft_putnbr(c % 10);
    }
}
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
*/
int	check_first_argument(char *pid)
{
	while(*pid)
	{
		if(*pid < '0' || *pid > '9')
			return (1);
		pid++;
	}
	return(0);
}

int main(int ac, char **av)
{
  if (ac != 3)
	  ft_putstr("Attention please ! wrong number of arguments\n");

  if(check_first_argument(av[1]) == 1)
	ft_putstr("Your PID is not correct\n");
}