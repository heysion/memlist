#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "memlist.h"
#include <mcheck.h> 

int main()
{
  void *p[4];
  void *dd[2];
  int i =0;

  setenv("MALLOC_TRACE","output.out",1);
  mtrace();

  for(;i<4;i++)
    {
      p[i]=cgmalloc(i+10);
    }

  cgfree();

  dd[0] = cgmalloc(100);
  dd[1] = cgmalloc(30);

  cgfree();
  return 0;
}
