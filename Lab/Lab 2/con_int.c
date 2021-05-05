#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n, int *opr)
{
  for (int i = (m > n ? n : m); i > 0; i--)
  {
    (*opr)++;
    if (m % i == 0 && n % i == 0)
    {
      return i;
    }
  }
}

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  int opr = 0;
  int result = gcd(m, n, &opr);
  printf("The gcd is %d and the operation count is -> %d\n", result, opr);
}