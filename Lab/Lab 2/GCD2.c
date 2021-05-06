#include <stdio.h>
#include <stdlib.h>

#define MAXFACTORS 1024

typedef struct
{
    int size;
    int factor[MAXFACTORS + 1];
    int exponent[MAXFACTORS + 1];
} FACTORIZATION;

void findFactors(int x, FACTORIZATION *factorization, int *count)
{
    int i, j = 1;
    int n = x, c = 0;
    int k = 1;
    factorization->factor[0] = 1;
    factorization->exponent[0] = 1;
    for (i = 2; i <= n; i++)
    {
        c = 0;
        while (1)
        {
            (*count)++;
            if (n % i == 0)
            {
                c++;
                n = n / i;
            }
            else
            {
                break;
            }
        }
        if (c > 0)
        {
            factorization->exponent[k] = c;
            factorization->factor[k] = i;
            k++;
        }
    }
    factorization->size = k - 1;
}

void DisplayFactorization(int x, FACTORIZATION factorization)
{

    int i;

    for (i = 0; i <= factorization.size; i++)
    {
        printf("%d", factorization.factor[i]);
        if (factorization.exponent[i] > 1)
            printf("^%d", factorization.exponent[i]);
        if (i < factorization.size)
            printf("*");

        else
            printf("\n");
    }
}

int middleschool(int m, int n, int *c)
{

    FACTORIZATION mfact, nfact;
    int r, mi, ni, i, k, x = 1, j;
    findFactors(m, &mfact, c);
    findFactors(n, &nfact, c);
    DisplayFactorization(m, mfact);
    DisplayFactorization(n, nfact);
    int min;
    i = 1;
    j = 1;
    while (i <= mfact.size && j <= nfact.size)
    {
        if (mfact.factor[i] < nfact.factor[j])
            i++;
        else if (nfact.factor[j] < mfact.factor[i])
            j++;
        else
        {
            min = mfact.exponent[i] > nfact.exponent[j] ? nfact.exponent[j] : mfact.exponent[i];
            x = x * mfact.factor[i] * min;
            i++;
            j++;
        }
    }
    return x;
}

int main()
{
    int m, n;
    int count = 0;
    int *cnt = &count;
    printf("Enter the two numbers whose GCD has to be calculated\n");
    scanf("%d", &m);
    scanf("%d", &n);
    printf("GCD of two numbers using middle school method is %d\n",
           middleschool(m, n, cnt));
    printf("count:%d\n", *cnt);
    return 0;
}