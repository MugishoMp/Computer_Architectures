#include <stdio.h>

#define N 16
static int q[N];

int main(void)
{
  int Z, c, Y;

  Z = 29;
  q[N-1] = Z;

  for (c = N - 2; c >= 0; --c)
    q[c] = q[c+1] - 1;

  Y = (q[0] + q[N/2] + q[N-1]) * 2;

  printf("%d\n", Y);

  return Y;
}
