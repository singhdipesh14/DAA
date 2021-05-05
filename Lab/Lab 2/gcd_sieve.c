#include <stdio.h>
#include <stdlib.h>

void sieve(int m, int arr[])
{
  for (int i = 2; i < m + 1; i++)
  {
    arr[i] = i;
  }
  int j;
  for (int i = 2; i < m + 1; i++)
  {
    if (arr[i] != 0)
    {
      j = i * i;
      while (j <= m)
      {
        arr[j] = 0;
        j = j + i;
      }
    }
  }
}

int pf(int n, int arr[], int *op)
{
  int narr[n + 1];
  sieve(n, narr);
  int i = 2;
  int cnt = 0;
  while (i <= n)
  {
    (*op)++;
    if (narr[i] != 0)
    {
      if (n % narr[i] == 0)
      {
        arr[cnt] = narr[i];
        n = n / narr[i];
        cnt++;
      }
      else
      {
        i++;
      }
    }
    else
    {
      i++;
    }
  }
  return cnt;
}

int gcd(int m, int n, int *opr)
{
  if (m == 0 || n == 0)
  {
    *opr = 1;
    return m == 0 ? n : m;
  }
  int marr[m], narr[n], op1 = 0, op2 = 0;
  int a = pf(m, marr, &op1);
  int b = pf(n, narr, &op2);
  *opr = op1 + op2;
  printf("Prime factors of %d -> \t", m);
  for (int i = 0; i < a; i++)
  {
    printf("%d\t", marr[i]);
  }
  printf("\nPrime factors of %d -> \t", n);
  for (int i = 0; i < b; i++)
  {
    printf("%d\t", narr[i]);
  }
  printf("\n");
  int i = 0, j = 0;
  int result = 1;
  while (i < a && j < b)
  {
    if (marr[i] == narr[j])
    {
      result *= marr[i];
      i++;
      j++;
    }
    else if (marr[i] < narr[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  return result;
}

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  int opr = 0;
  int result = gcd(m, n, &opr);
  printf("The gcd is %d and the operation count is -> %d\n", result, opr);
}