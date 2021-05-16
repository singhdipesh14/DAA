#include <stdio.h>
#include <stdlib.h>

int solve(int arr[], int n);
int complement(int arr[], int n, int res[], int mn[], int mnn);
void print(int sub[], int ls, int mainarr[], int lm);

int main()
{
	int n;
	printf("Enter size of array to be input : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array : ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = solve(arr, n);
	return 0;
}

int solve(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	if (sum % 2 == 1)
	{
		printf("Partition not possible\n");
		return 0;
	}
	int compare = sum / 2;
	// printf("half sum = %d\n", compare);
	int count = 0;
	int power = 1 << n;
	// printf("power = %d\n", power);
	for (int i = 1; i < power; i++)
	{
		int m[n];
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				m[cnt++] = arr[j];
			}
		}
		int arrSum = 0;
		for (int j = 0; j < cnt; j++)
		{
			arrSum += m[j];
		}
		// printf("array sum : %d\n", arrSum);
		if (arrSum == compare)
		{
			printf("Partition Possible\n{\t");
			for (int j = 0; j < cnt; j++)
			{
				printf("%d\t", m[j]);
			}
			printf("}\n{\t");
			print(m, cnt, arr, n);
			return count;
		}
	}
	printf("Partition not possible\n");
	return count;
}

void print(int sub[], int ls, int mainarr[], int lm)
{
	int l = lm - ls;
	int i, j, k = 0, flag;
	for (i = 0; i < lm; i++)
	{
		flag = 1;
		for (j = 0; j < ls; j++)
		{
			if (mainarr[i] == sub[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("%d\t", mainarr[i]);
		}
	}
	printf("}\n");
}