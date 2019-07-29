#include <sys/time.h>
#include <stdio.h>

int main()
{
  struct timeval tv;
  struct timeval tv1;
  gettimeofday(&tv, NULL);
  for ( int i=0; i < 1000001; ++i )
  {
    printf("\r%d", i);
  }
  printf("\n");
  gettimeofday(&tv1, NULL);

  printf("escape: %ld\n", tv1.tv_sec - tv.tv_sec);

  return 0;
}
