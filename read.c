#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define HIDE_DEV "/dev/hideproc"

int main(void)
{
	int fd = open(HIDE_DEV, O_RDWR);
	char buf[1000];
	if (fd < 0) {
		perror("Failed to open character device");
		exit(1);
	}
	 ssize_t offset = read(fd, buf, 1);
	 printf("%s", buf);
	 printf("offset: %ld", offset);

    return 0;
}
