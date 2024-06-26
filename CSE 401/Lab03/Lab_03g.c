#include <stdlib.h> /* needed to define exit() */
#include <unistd.h> /* needed for fork() and getpid() */
#include <stdio.h> /* needed for printf() */
void runit() {
	printf("About to run ls\n");
	execlp("ls", "ls", "-aF", "/", (char*)0);
	perror("execlp"); /* if we get here, execlp failed */
	exit(1);
}

int main() {
	int pid; /* process ID */
	switch (pid = fork()) {
	case 0: /* a fork returns 0 to the child */
	runit();
	break;
	default: /* a fork returns a pid to the parent */
	sleep(5); /* sleep for 5 seconds */
	printf("I'm still here!\n");
	break;
	case -1: /* something went wrong */
	perror("fork");
	exit(1);
	}
	exit(0);
}




