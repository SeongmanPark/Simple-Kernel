#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/minco", O_RDWR);
	if(fd == -1) 
	{
		printf("ERROR\n");
	}
	else printf("go\n");
	close(fd);
	return 0;
}

