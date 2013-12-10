FILE1 = bitcnt_1.c bitcnt_2.c bitcnt_3.c bitcnt_4.c bitcnts.c bitfiles.c bitstrng.c bstr_i.c 
FILE2 = bitcnt_1.c bitcnt_2.c bitcnt_3.c bitcnt_4.c bitcnts_gem5.c bitfiles.c bitstrng.c bstr_i.c
all: bitcnts bitcnts_gem5
gem5: bitcnts_gem5
bitcnts: ${FILE1} Makefile
	gcc -static ${FILE1} -lcrypto -O3 -o bitcnts
bitcnts_gem5: ${FILE2} Makefile
	gcc -static ${FILE2} -lcrypto -O3 -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S -o bitcnts_gem5
clean:
	rm -rf bitcnts output*
