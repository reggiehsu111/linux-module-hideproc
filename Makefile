CC = gcc
CFLAGS := -Wall -g

MODULENAME := hideproc
obj-m += $(MODULENAME).o
$(MODULENAME)-y += main.o

KERNELDIR ?= /lib/modules/`uname -r`/build
PWD       := $(shell pwd)

all: test read
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm test read
test: test.c
	$(CC) $(CFLAGS) $^ -o $@
read: read.c
	$(CC) $(CFLAGS) $^ -o $@
load:
	sudo insmod $(MODULENAME).ko
unload:
	sudo rmmod $(MODULENAME) || true >/dev/null
