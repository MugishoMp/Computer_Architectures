#include <stdio.h>

static int A[] = { 16, 13, 3, 19, 31, 18, 24, 28, 32, 0,
                   10, 4, 8, 29, 36, 11, 20, 27, 38, 37 };


static void
vec_add(int A[], const int n, const int s)
{
  for (int i = 0; i < n; ++i)
    A[i] += s;
}

int main(void)
{
  vec_add(A, sizeof(A) / sizeof(int), 214);

  return 0;
}
