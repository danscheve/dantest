#include <stdio.h>
//float av(float *farray, size_t size);
//int setCount (float val);
int main (int argc, char **argv)
{
  unsigned long long i, userInput, ret;
  printf("\nenter a number between 1 and 100 : ");
  scanf("%llu", &ret);
  if (ret > 0 & ret < 101)
  {
    userInput = ret;
    for (i=1; i<userInput; ++i)
    {
      ret *= i;
      printf("ret: %llu' i: %llu\n", ret, i);
    }
    printf ("the factorial of %llu is %llu\n", userInput, ret);
  }
  else
    printf ("Try again\n");
  return 0;
}


