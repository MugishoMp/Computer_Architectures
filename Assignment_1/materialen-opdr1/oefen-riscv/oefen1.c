#include <stdio.h>

#define N 16

static int A[N], B[N];

int main(void)
{
  int C, i;

  for (i = 0; i < N; ++i)
    A[i] = i * 2;

  C = 95;

  B[0] = 0;
  for (i = 1; i < N; ++i)
    B[i] = A[i-1] + C;

  printf("%d\n", B[N-1]);

  return A[N-1];
}
