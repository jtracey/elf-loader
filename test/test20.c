#define _GNU_SOURCE 1
#include <dlfcn.h> 
#include <stdio.h>

int main (int argc, char *argv[])
{
  printf ("enter\n");
  void *h = dlmopen (LM_ID_NEWLM, argv[0], RTLD_LAZY);
  if (h != 0)
    {
      printf ("loaded self second time\n");
    }
  dlclose (h);
  printf ("leave\n");
  return 0;
}
