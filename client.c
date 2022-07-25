#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	send_msg(int pid, char *msg)
{
	int	nbit;
	int	which_bit;
	size_t	i;
	int kill_check;
	
	i = 0;
	while (msg[i] != '\0')
	{
		nbit = 7;
		while (nbit >= 0)
		{
			which_bit = (msg[i] >> nbit) & 1;
			if (which_bit == 1)
			{
				//printf("%d", which_bit);
				kill_check = kill((pid_t)pid, SIGUSR1);
			}
			if (which_bit == 0)
			{
				//printf("%d", which_bit);
				kill_check = kill((pid_t)pid, SIGUSR2);
			}
			if (kill_check == -1)
				exit(1);
			usleep(100);
			nbit--;
		}
		i++;
	}
	return ;
}

int main(int argc, char **argv)
{
	int	pid;
	char	*sig;

	if (argc != 3) //pid > 0
		return (0);
	pid = atoi(argv[1]);
	sig = argv[2];
	send_msg(pid, sig);
	//messenger(pid, sig);
	return (0);
}
