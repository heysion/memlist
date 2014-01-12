#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "memlist.h"

int main()
{
  char *p[3];
  int i =0;

  for(;i<3;i++)
    {
      p[i]=(char *)cgmalloc(i+10);
    }

  cgfree();
  return 0;
}
