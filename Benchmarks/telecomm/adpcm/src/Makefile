#
# Makefile for adpcm and test programs
# -------------------

#####################################################################
# Added by C. Lee.
#
# On Sun machines, gcc need to be informed whether the machines have
# integer multipliers by specifying this option: -mv8.
#
# Also, on Sun machines, in order to use the SPIXTOOLS and SHADE,
# uncomment this option: -static.
#
CC = gcc
LFLAGS = -mv8
LFLAGS = $(LFLAGS) -static
#
# End of addition
######################################################################
CFLAGS = -static -O3

# May need this on a sun:
# CFLAGS=-O -I/usr/demo/SOUND

ALLSRC=README adpcm.2 Makefile adpcm.h libst.h adpcm.c timing.c rawcaudio.c \
	rawdaudio.c suncaudio.c sgicaudio.c sgidaudio.c hello.adpcm.uu rawcaudio_gem5.c rawdaudio_gem5.c

all: adpcm.o rawcaudio rawdaudio rawcaudio_gem5 rawdaudio_gem5 timing
	cp rawcaudio rawdaudio rawdaudio_gem5 rawcaudio_gem5 timing ../bin/.
gem5: rawcaudio_gem5 rawdaudio_gem5
sgi: all sgicaudio sgidaudio

sun: all suncaudio sundaudio

adpcm.o: adpcm.h

suncaudio: suncaudio.o adpcm.o
	$(CC) adpcm.o suncaudio.o -o suncaudio -L/usr/demo/SOUND -laudio

sundaudio: suncaudio
	cp suncaudio sundaudio

sgicaudio: sgicaudio.o adpcm.o
	$(CC) sgicaudio.o adpcm.o -o sgicaudio -laudiofile -lm

sgidaudio: sgidaudio.o adpcm.o
	$(CC) sgidaudio.o adpcm.o -o sgidaudio -laudiofile -lm

rawcaudio_gem5: rawcaudio_gem5.o adpcm.o
	$(CC) $(CFLAGS) rawcaudio_gem5.o adpcm.o -o rawcaudio_gem5 -lcrypto -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S 

rawcaudio: rawcaudio.o adpcm.o
	$(CC) $(CFLAGS) rawcaudio.o adpcm.o -o rawcaudio

rawdaudio_gem5: rawdaudio_gem5.o adpcm.o
	$(CC) $(CFLAGS) rawdaudio_gem5.o adpcm.o -o rawdaudio_gem5 -lcrypto -I ~/clean_gem5/gem5-stable/util/m5 ~/clean_gem5/gem5-stable/util/m5/m5op_x86.S 

rawdaudio: rawdaudio.o adpcm.o
	$(CC) $(CFLAGS) rawdaudio.o adpcm.o -o rawdaudio

timing: timing.o adpcm.o
	$(CC) $(CFLAGS) timing.o adpcm.o -o timing

adpcm.shar: $(ALLSRC)
	shar $(ALLSRC) > adpcm.shar

# Added by C. Lee
clean:
	rm -f *.o ; rm rawcaudio rawdaudio timing ; rm -f ../bin/* ../output*
