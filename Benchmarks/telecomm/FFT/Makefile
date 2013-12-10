OBJ = main.o fftmisc.o  fourierf.o
FILE = main.c fftmisc.c  fourierf.c
CFLAGS = -static -O3 -g 
LDFLAGS = -lcrypto -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S
OBJ_GEM5 =main_gem5.o fftmisc.o  fourierf.o
FILE_GEM5 = main_gem5.c fftmisc.c  fourierf.c

fft: ${OBJ} Makefile                                             
	gcc  ${CFLAGS} ${OBJ} -o fft -lm 

fft_gem5: ${OBJ_GEM5} Makefile
	gcc  ${CFLAGS} ${OBJ_GEM5} -o fft_gem5 -lm ${LDFLAGS}
gem5: fft_gem5
fftmisc.o: fftmisc.c
	gcc ${CFLAGS} -c fftmisc.c
fourierf.o: fourierf.c
	gcc ${CFLAGS} -c fourierf.c
main.o: main.c
	gcc ${CFLAGS} -c main.c
main_gem5.o: main_gem5.c
	gcc ${CFLAGS} -c main_gem5.c 
clean:
	rm -rf *.o fft output* fft_gem5
