#include <netinet/in.h>
#include <stdint.h>
#include <openssl/aes.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <poll.h>
#include <string.h>
#include <stdio.h>
#include "rdtsc.h"
#include <math.h>
double packets;
double ttotal;
double t[16][256];
double tsq[16][256];
long long tnum[16][256];
double u[16][256];
double udev[16][256];
char n[16];
int s;
int size;
uint64_t lock = 1;
uint64_t unlock = 0;
unsigned char key[16];
AES_KEY expanded;
unsigned char zero[16];
unsigned char scrambledzero[16];
char packet[2048];
char out[48];

unsigned char workarea[16*3];

char in[1537];
int r;

void tally(double timing) {
  int j;
  int b;
  j = 0;
  b = 255 & (int) n[j]; ++packets;
  ttotal += timing;
  t[j][b] += timing;
  tsq[j][b] += timing * timing; tnum[j][b] += 1;
}

void printpatterns(void)
{
  int j;
  int b;
  double taverage;
  taverage = ttotal / packets;
  j = 0;
  for (b = 0;b < 256;++b) {
    u[j][b] = t[j][b] / tnum[j][b]; udev[j][b] = tsq[j][b] / tnum[j][b]; udev[j][b] -= u[j][b] * u[j][b]; udev[j][b] = sqrt(udev[j][b]);
    printf("%2d %4d %3d %lld %.3f %.3f %.3f %.3f\n" ,j
           ,size
           ,b
           ,tnum[j][b]
           ,u[j][b]
           ,udev[j][b]
           ,u[j][b] - taverage
           ,udev[j][b] / sqrt(tnum[j][b])
           );
  }
  fflush(stdout);
}

int timetoprint(long long inputs) {
  if (inputs < 10000) return 0;
  if (!(inputs & (inputs - 1))) return 1; return 0;
}

main(int argc,char **argv) {
  if (read(0,key,sizeof key) < sizeof key) return 111; 
  AES_set_encrypt_key(key,128,&expanded); 
  /* preload */
  m5_setpid(lock);
  AES_encrypt(packet,workarea,&expanded);
  m5_setpid(unlock);
  
  int power2=4;
  int j;
  size = 16;
  struct pollfd p;
  long long inputs = 0;
  
  // study;
  for (;;){
    for (;;){
      if (size < 16) continue;
      if (size > sizeof packet) continue;
      for (j = 0; j < size; ++j)
        packet[j] = random();
      j = 0;
      n[j] = packet[j];
      
      int i;
      for (i = 0;i < 48;++i) out[i] = 0; 
      
      
      i = 0;
      out[i] = packet[i];
      for (i = 0;i < 16;++i) workarea[i] = packet[i];
      m5_setpid(lock);
      *(unsigned long long *)(out + 32) = rdtsc(); 
      AES_encrypt(packet,workarea,&expanded);
      /* a real server would now check AES-based authenticator, */ /* process legitimate packets, and generate useful output */
      *(unsigned long long *) (out + 40) = rdtsc();
      m5_setpid(unlock);
      i = 0;
      out[16 + i] = scrambledzero[i];
      
      
      
      unsigned long long timing;
      timing = *(unsigned long long *) (out + 40);
      timing -= *(unsigned long long *) (out + 32);
      
      tally(timing);break;
    }
    
    ++inputs;
    if (timetoprint(inputs)){
      printpatterns();
    }
    if (power2 == 17){
      return 1;
    }
  }
}
