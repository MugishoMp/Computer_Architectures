static int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int compute_sum(int values[], int N)
{
  int sum = 0;

  for (int i = 0; i < N; i++)
    sum += values[i];

  return sum;
}

int main(void)
{
  return compute_sum(values, sizeof(values)/sizeof(int));
}
