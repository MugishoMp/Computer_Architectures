/*
 * Skeleton code for use with Computer Architecture 2022 assignment 3,
 * LIACS, Leiden University.
 */

#include "timing.h"

#include <immintrin.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include <math.h>


#ifndef N_REPEAT
#  error "Need to define N_REPEAT in the Makefile"
#endif


/* Size of the matrix. We use N x N square matrices.
 *
 * We define a default here, if N was not set in the Makefile.
 */
#ifndef N
#  define N 512
#endif /* !defined N */

/* Size of the block. We use N x N square matrices.
 *
 * We define a default here, if N was not set in the Makefile.
 */
#ifndef BLOCK
#  error "Need to define N_REPEAT in the Makefile"
#endif /* !defined N */

/* TODO: When you copy this file to implement loop blocking, you likely wan
 * to include a define for the block size as well.
 */


static void
matrix_clear(float matrix[N][N])
{
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < N; ++j)
      matrix[i][j] = 0;
}

static void
matrix_init_identity(float matrix[N][N])
{
  matrix_clear(matrix);

  for (size_t i = 0; i < N; ++i)
    matrix[i][i] = 1.;
}

static void
matrix_init_random(float matrix[N][N])
{
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < N; ++j)
      matrix[i][j] = rand() % 100;
}

void
matrix_dump(float matrix[N][N])
{
  for (size_t i = 0; i < N; ++i)
    {
      for (size_t j = 0; j < N; ++j)
        printf("%f ", matrix[i][j]);
      printf("\n");
    }
}

bool
matrix_equal(float A[N][N], float B[N][N])
{
  for (size_t i = 0; i < N; ++i)
    for (size_t j = 0; j < N; ++j)
      if (fabsf(A[i][j] - B[i][j]) > 0.000001)
        return false;

  return true;
}

// static void
// matrix_multiply(float C[N][N], const float A[N][N], const float B[N][N])
// {
//   for (size_t row = 0; row < N; row = row + BLOCK) {
//     for (size_t col = 0; col < N; col = col + BLOCK) {
      
//       for (int blockRow = row; blockRow < row + BLOCK; blockRow++) {
//         for (int blockCol = col; blockCol < col + BLOCK; blockCol++) {
//           float product = 0.0;

//           for (size_t dot = 0; dot < N; dot++) {
//             product += A[blockRow][dot] * B[dot][blockCol];
//           }
//           C[blockRow][blockCol] = product;
//         }
//       }
//     }
//   }   
// }
static void
matrix_multiply(float C[N][N], const float A[N][N], const float B[N][N])
{
  for (size_t jj = 0; jj < N; jj =jj + BLOCK) {
    for (size_t kk = 0; kk < N; kk = kk + BLOCK) {
      for (size_t i = 0; i < N; i++) {

        size_t max1 = (jj + BLOCK < N) ? jj + BLOCK : N;
        for (size_t j = jj; j < max1; j++) {
          float r = 0.0;

          size_t max2 = (kk + BLOCK < N) ? kk + BLOCK : N;
          for (size_t k = kk; k < max2; k++)
            r = r + A[i][k] * B[k][j];

          C[i][j] += r;
        }
      }
    }
  }
    
}


int
main(int argc, char **argv)
{
  /* We use this "magic" to allocate real two-dimensional arrays, that
   * are aligned at 64-bytes (cache line size).
   */
  float (*A)[N] = (float (*)[N])_mm_malloc(N * N * sizeof(float), 64);
  float (*B)[N] = (float (*)[N])_mm_malloc(N * N * sizeof(float), 64);
  float (*C)[N] = (float (*)[N])_mm_malloc(N * N * sizeof(float), 64);

  struct timespec init_start_time, init_end_time;
  get_time(&init_start_time);

  matrix_init_identity(A);
  matrix_init_random(B);

  get_time(&init_end_time);

  /* Perform the matrix multiplication */
  struct timespec compute_start_time, compute_end_time;
  get_time(&compute_start_time);

  for (int Z = 0; Z < N_REPEAT; ++Z)
    matrix_multiply(C, A, B);

  get_time(&compute_end_time);

#ifdef ENABLE_TIMING
  /* Output result in CSV for easy processing */
  /* N,init time,n_repeat,runtime */
  printf("%d,%f,%d,%f\n",
         N,
         get_elapsed_ms(&init_end_time, &init_start_time),
         N_REPEAT,
         get_elapsed_ms(&compute_end_time, &compute_start_time));
#endif /* ENABLE_TIMING */

#if 0
  /* For debugging */
  if (!matrix_equal(C, B))
    fprintf(stderr, "Matrices are not equal!!\n");
#endif

  _mm_free(A);
  _mm_free(B);
  _mm_free(C);

  return 0;
}
