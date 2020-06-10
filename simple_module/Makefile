KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build
CC=gcc

TARGET=hi
obj-m = minco_module.o

all:
	@$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) modules

hi:
	$(CC) -o $@ $@.c

clean:
	@$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) clean
	rm -f *.o $(TARGET)