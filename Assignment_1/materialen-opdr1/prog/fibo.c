
extern void print_roman(int);

static int fibs[10];

int main(void)
{
    int i;

    /* compute the fibonacci sequence */
    fibs[0] = fibs[1] = 1;
    for (i = 2; i < 10; ++i)
        fibs[i] = fibs[i-1] + fibs[i-2];

    /* display it on the simulation output */
    for (i = 0; i < 10; ++i)
        print_roman(fibs[i]);

    return 0;
}
