all: susan susan_gem5
gem5: susan_gem5
susan: susan.c Makefile
	gcc -static -O4 -o susan susan.c -lm 
susan_gem5: susan_gem5.c Makefile
	gcc -static -O4 -o susan_gem5 susan_gem5.c -lm -lcrypto -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S
clean:
	rm -rf susan output*
