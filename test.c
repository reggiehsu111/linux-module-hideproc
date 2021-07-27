#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define HIDE_DEV "/dev/hideproc"
int N=10;

int main(void)
{
	int pid;
    for (int i = 0; i < N; i++) {
       	pid = fork();
		if (pid) {
			// maximum pid has 5 digits
			char write_buf[11];
			snprintf(write_buf, 11, "add %d", pid);
			int fd = open(HIDE_DEV, O_RDWR);
			if (fd < 0) {
        		perror("Failed to open character device");
        		exit(1);
			}
			 write(fd, write_buf, strlen(write_buf));

		} else {
			break;
		}
    }

    return 0;
}
