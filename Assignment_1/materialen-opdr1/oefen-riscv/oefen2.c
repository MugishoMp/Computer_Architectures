#include <stdio.h>
#define N 16

static int f[N];

int main(void)
{
  int Q, x;

  Q = 31;
  f[0] = f[1] = Q;

  for (x = 2; x < N; ++x)
    f[x] = f[x-1] + f[x-2];

  printf("%d\n", f[N-1]);

  return f[N-1];
}
