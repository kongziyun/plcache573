#include <openssl/aes.h>
#include <string.h>
#include <stdio.h>
unsigned char zero[16];
unsigned char scrambledzero[16];
unsigned char ciphertext[16];
double weight[16][256];
double maxweight[16];
unsigned char key[16];
AES_KEY expanded;

void doit(int b)
{
  int x;
  if (b == 16) {
    AES_set_encrypt_key(key,128,&expanded);
    AES_encrypt(zero,scrambledzero,&expanded);
    if (!memcmp(scrambledzero,ciphertext,16)) {
      printf("The key is");
      for (x = 0;x < 16;++x) printf(" %02x",key[x]);
      printf(".\n");
    }
    return;
  }
  for (x = 0;x < 256;++x)
    if (weight[b][x] == maxweight[b]) {
      key[b & 15] = x;
      doit(b + 1);
    }
}

int main()
{
  int b;
  int x;
  int n;
  int i;
  for (b = 0;b < 16;++b) {
    scanf("%x",&x);
    ciphertext[b] = x;
  }
  while (scanf("%d",&n) == 1) {
    scanf("%d",&b);
    for (i = 0;i < n;++i) {
      scanf("%x",&x);
      weight[b & 15][x & 255] += 1.0 / n;
    }
  }
  for (b = 0;b < 16;++b)
    for (x = 0;x < 256;++x)
      if (weight[b][x] > maxweight[b])
	maxweight[b] = weight[b][x];
  doit(0);
  return 0;
}
