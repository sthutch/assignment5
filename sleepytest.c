#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv) {

	int sleepTime = atoi(argv[1]);
	int sleepy = open("/dev/sleepy0", O_RDWR);

	if(sleepy == -1) {
		printf("Open file failed\n");
		return -1;
	}

	while(1) {
		printf("Calling write...\n");
		ssize_t result = write(sleepy, &sleepTime, 4);
		if (result == 0) {
			printf("Woken up after full sleep\n");
		}
		else {
			printf("Woken up with %d seconds remaining\n", (int) result);
		}
	}
}
