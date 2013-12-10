/* testd - Test adpcm decoder */
#include <openssl/aes.h>
#include "rdtsc.h"
#include "adpcm.h"
#include <stdio.h>

struct adpcm_state state;

#define NSAMPLES 1000

char	abuf[NSAMPLES/2];
short	sbuf[NSAMPLES];

main() {
  unsigned char key[16], zero[16], scrambledzero[16]; 
AES_KEY expanded;                                     
unsigned long long ago;                               
if (read(0, key, sizeof key) < sizeof key) return 111;
AES_set_encrypt_key(key, 128, &expanded);             
m5_setpid(1);                                         
AES_encrypt(zero, scrambledzero, &expanded);          
m5_setpid(0);                                         
                                                      
ago = rdtsc(); 
    int n;

    while(1) {
	n = read(0, abuf, NSAMPLES/2);
	if ( n < 0 ) {
	    perror("input file");
	    exit(1);
	}
	if ( n == 0 ) break;
	adpcm_decoder(abuf, sbuf, n*2, &state);
	write(1, sbuf, n*4);
    }
    fprintf(stderr, "Final valprev=%d, index=%d\n",
	    state.valprev, state.index);
ago =rdtsc() - ago;
fprintf(stderr, "\n\nCycle count: %lld\n\n", ago); 
   exit(0);
}
