/* NIST Secure Hash Algorithm */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sha.h"
#include "rdtsc.h"
#include <openssl/aes.h>
int main(int argc, char **argv)
{
 unsigned char key[16], zero[16], scrambledzero[16];
AES_KEY expanded;
unsigned long long ago;
if (read(0, key, sizeof key) < sizeof key) return 111;
AES_set_encrypt_key(key, 128, &expanded);
m5_setpid(1);
AES_encrypt(zero, scrambledzero, &expanded);
m5_setpid(0);

ago = rdtsc();
 
    FILE *fin;
    SHA_INFO sha_info;

    if (argc < 2) {
	fin = stdin;
	sha_stream(&sha_info, fin);
	sha_print(&sha_info);
    } else {
	while (--argc) {
	    fin = fopen(*(++argv), "rb");
	    if (fin == NULL) {
		printf("error opening %s for reading\n", *argv);
	    } else {
		sha_stream(&sha_info, fin);
		sha_print(&sha_info);
		fclose(fin);
	    }
	}
    }

  ago = rdtsc() - ago;
  printf("\n\nCycle count: %lld\n\n", ago);
    return(0);
}
