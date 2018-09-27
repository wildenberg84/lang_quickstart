#include <assert.h>
#include <errno.h>
#include "Includes.h"

void error()
{
   FILE *fp;

   fp = fopen("nosuchfile.txt", "r");
   if( fp == NULL ) {
      fprintf(stderr, "Value of errno: %d\n", errno);
      fprintf(stderr, "Error opening file: %s\n", strerror(errno));
   } else {
      fclose(fp);
   }

   return;
}

void test()
{
    int i = 10;

    assert(i < 10);

    return;
}
