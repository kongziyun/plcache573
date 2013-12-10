# By default, the code is compiled for a "big endian" machine.
# To compile on a "little endian" machine set the LITTLE_ENDIAN flag.
# To make smaller object code, but run a little slower, don't use UNROLL_LOOPS.
# To use NIST's modified SHA of 7/11/94, define USE_MODIFIED_SHA

CC = gcc
CFLAGS = -static -O3 -Wall -lcrypto
gem5: sha_gem5
sha:	sha_driver.o sha.o
	$(CC) -static -o $@ sha_driver.o sha.o
	strip $@
sha_gem5: sha_driver_gem5.o sha.o
	$(CC) -static -o $@ sha_driver_gem5.o sha.o -lcrypto -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S
	strip $@
clean:
	rm -rf *.o sha output*
