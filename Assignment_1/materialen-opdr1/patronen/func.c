int func(void)
{
  return 42;
}

int main(void)
{
  int a = func();
  a += 4;

  return a;
}
