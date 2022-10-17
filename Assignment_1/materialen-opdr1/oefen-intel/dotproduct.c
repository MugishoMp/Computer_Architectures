#include <stdio.h>

static int A[] = { 16, 13, 3, 19, 31, 18, 24, 28, 32, 0,
                   10, 4, 8, 29, 36, 11, 20, 27, 38, 37 };
static int B[] = { 8, 7, 26, 17, 18, 16, 24, 11, 35, 27,
                   4, 1, 29, 19, 36, 37, 28, 9, 32, 5 };

static int
dot_product(const int A[], const int B[], int n)
{
  int res = 0;

  for (int i = 0; i < n; ++i)
    res += A[i] * B[i];

  return res;
}

int main(void)
{
  int dot;

  dot = dot_product(A, B, sizeof(A) / sizeof(int));

  printf("%d\n", dot);

  return 0;
}
