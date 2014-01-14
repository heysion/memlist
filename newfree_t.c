#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "memlist.h"
#include <mcheck.h> 

int main()
{
  char *p[3];
  int i =0;

  setenv("MALLOC_TRACE","output.out",1);
  mtrace();

  for(;i<3;i++)
    {
      p[i]=(char *)cgmalloc(i+10);
    }

  cgfree();

  return 0;
}
