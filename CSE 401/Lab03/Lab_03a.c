#include <stdlib.h> /* needed to define exit() */
#include <unistd.h> /* needed to define getpid() */
#include <stdio.h> /* needed for printf() */
int main() {
	printf("my process ID is %d\n", getpid());
	exit(0);
	}
