FILE1 = qsort_small.c
FILE2 = qsort_large.c

all: qsort_small qsort_large qsort_small_gem5
gem5: qsort_small_gem5
qsort_small: qsort_small.c Makefile
	gcc -static qsort_small.c -O3 -o qsort_small -lm
qsort_large: qsort_large.c Makefile
	gcc -static qsort_large.c -O3 -o qsort_large -lm
qsort_small_gem5: qsort_small_gem5.c Makefile
	gcc -static qsort_small_gem5.c -lcrypto -o qsort_small_gem5 -lm -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S
clean:
	rm -rf qsort_small qsort_large output*
