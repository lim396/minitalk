#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t g_sig = 0;

void hoge() {
	static char	c = '\0';
	static int	i = 0;

	c = c << 1;
	if (g_sig == SIGUSR1)
	{
		//write(1, "1", 1);
		c |= 1;
	}
	//if (bit == SIGUSR2)
	//	write(1, "0", 1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = '\1';
	}
}

void	handler(int bit)
{
	g_sig = bit;
	// static char	c = '\0';
	// static int	i = 0;

	// c = c << 1;
	// if (bit == SIGUSR1)
	// {
	// 	//write(1, "1", 1);
	// 	c |= 1;
	// }
	// //if (bit == SIGUSR2)
	// //	write(1, "0", 1);
	// i++;
	// if (i == 8)
	// {
	// 	write(1, &c, 1);
	// 	i = 0;
	// 	c = '\0';
	// }
}

int main()
{
	int pid;
	int	pgid;

	pid = getpid();
	pgid = getpgid(pid);
	printf("%d\n", pid);
	printf("%d\n", pgid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		pause();
		hoge();
	}
	return (0);
}
