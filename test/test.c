#include <stdio.h>
#include <sys/errno.h>
#include <string.h>

int main(void)
{
	for (int i=1; i<107; i++)
		printf("errno = %d msg = [%s]\n", i, strerror(i));
	return (0);
}
