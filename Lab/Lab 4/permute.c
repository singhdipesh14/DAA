#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void nextPermute(int *cur, int num);
void reverse(int *cur, int start, int end);
int findCeil(int *cur, int first, int l, int h);
int fact(int num);
int main()
{
	int arr[] = {0, 1, 2, 3};
	int n = 4;
	int *cur = arr;
	for (int i = 0; i < fact(n); i++)
	{
		printf("%dth permutation : ", i + 1);
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");
		nextPermute(cur, n);
	}
	return 0;
}

int fact(int num)
{
	int result = 1;
	for (int i = 1; i <= num; i++)
	{
		result *= i;
	}
	return result;
}

void nextPermute(int *cur, int num)
{
	int i;
	for (i = num - 2; i >= 0; --i)
		if (cur[i] < cur[i + 1])
			break;
	int ceilIndex = findCeil(cur, cur[i], i + 1, num - 1);
	swap(cur, i, ceilIndex);
	reverse(cur, i + 1, num - 1);
}
void reverse(int *cur, int start, int end)
{
	while (start < end)
	{
		swap(cur, start, end);
		start++;
		end--;
	}
}
int findCeil(int *cur, int first, int l, int h)
{
	int ceilIndex = l;
	for (int i = l + 1; i <= h; i++)
		if (cur[i] > first && cur[i] < cur[ceilIndex])
			ceilIndex = i;

	return ceilIndex;
}