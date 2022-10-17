int foo(int a)
{
  int b = -1;
  if (a < 10)
    b = 2 * a;
  else if (a > 40)
    b = 3 * a;
  else
    b = a;
  return b;
}

int main(void)
{
  int a = 41;
  int b = foo(a);

  return b;
}
