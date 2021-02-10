#include <stdlib.h>
#include <stdio.h>

int fib_rec(int n)
{
  int i, j;
  if (n<2)
    return n;
  else
    {
       i=fib_rec(n-1);
       j=fib_rec(n-2);
       return i+j;
    }
}

int fib_omp(int n)
{
  int i, j;
  if (n<2)
    return n;
  else
    {
    {
       #pragma omp task shared(i) firstprivate(n)
       i=fib_omp(n-1);

       #pragma omp task shared(j) firstprivate(n)
       j=fib_omp(n-2);

    }
    #pragma omp taskwait
    return i+j;
    }
}

int fib_hyb(int n)
{
  int i, j;
  if (n<35)
    return fib_rec(n);
  else
    {
    {
       #pragma omp task shared(i) firstprivate(n)
       i=fib_hyb(n-1);

       #pragma omp task shared(j) firstprivate(n)
       j=fib_hyb(n-2);

    }
    #pragma omp taskwait
    return i+j;
    }
}


int main(int argc, char *argv[])
{
  int n,f;
  if (argc > 1)
    n= atoi(argv[1]);
  else
  {
    printf("Enter n \n");
    scanf("%d", &n);
  }
  #pragma omp parallel shared(n)
  {
    #pragma omp single nowait
    f=fib_hyb(n);
  }
  printf("n %d fibonacci de n %d \n",n,f);
  return 0;
}
