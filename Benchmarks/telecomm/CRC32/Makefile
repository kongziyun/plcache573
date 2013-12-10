crc: crc_32.c Makefile
	gcc -static crc_32.c -O3 -o crc 
gem5: crc_gem5
crc_gem5: crc_32_gem5.c Makefile
	gcc -static crc_32_gem5.c -O3 -o crc_gem5 -lcrypto -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S
clean:
	rm -rf crc output* 
