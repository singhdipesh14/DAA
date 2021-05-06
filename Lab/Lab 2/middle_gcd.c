#include <stdio.h>
#include <stdlib.h>

int isPrime(int n, int *count)
{
  int result = 1;
  for (int i = 2; i < n / 2; i++)
  {
    (*count)++;
    if (n % i == 0)
    {
      result = 0;
      break;
    }
  }
  return result;
}

int pf(int a, int arr[], int *count)
{
  int i = 2;

  int cnt = 0;
  arr[cnt] = 1;
  cnt++;
  while (i <= a)
  {
    if (isPrime(i, count))
    {
      if (a % i == 0)
      {
        arr[cnt] = i;
        a = a / i;
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
  int marr[m];
  int narr[n];
  int op1 = 0, op2 = 0;
  int a = pf(m, marr, &op1);
  int b = pf(n, narr, &op2);
  *opr = op1 + op2;
  printf("Prime factors of %d -> \t", m);
  for (int i = 1; i < a; i++)
  {
    printf("%d\t", marr[i]);
  }
  printf("\nPrime factors of %d -> \t", n);
  for (int i = 1; i < b; i++)
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
  int a, b;
  scanf("%d %d", &a, &b);
  int opr = 0;
  int result = gcd(a, b, &opr);
  printf("The gcd of %d and %d is -> %d and operation count is -> %d\n", a, b, result, opr);
}