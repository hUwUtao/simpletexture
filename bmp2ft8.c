#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "lib/bmpread.c"

int main (int argc, char** argv) {
  const char* file = NULL;
  bmpread_t bmp;
  unsigned int flags = 0;
  flags |= BMPREAD_ANY_SIZE;
  file = argv[1];
  if(argc <= 1) {
    fprintf(stderr, "Error: Not enough params, use %s in.bmp out.ft8\n", argv[0]);
    return 1;
  }

  if(!bmpread(file, flags, &bmp)){
    fprintf(stderr, "%s\n", "Error: Cannot open input file");
    return 1;
  }
  FILE* fs = fopen(argv[2], "wb");

  if(!fs) {
    fprintf(stderr, "%s\n", "Error: Cannot write output file");
    return 1;
  }
  fwrite((unsigned int *)&bmp.width, sizeof(unsigned int), 1, fs);
  fwrite((unsigned int *)&bmp.height, sizeof(unsigned int), 1, fs);
  fputs(bmp.data, fs);
  fclose(fs);
  return 0;
}
