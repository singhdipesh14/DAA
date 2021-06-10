#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		int v = arr[i];
		int k = i;
		int flag = 0;
		while (!flag && 2 * k <= n)
		{
			int j = 2 * k;
			if (j < n)
			{
				if (arr[j] < arr[j + 1])
				{
					j++;
				}
			}
			if (v < arr[j])
			{
				arr[k] = arr[j];
				k = j;
			}
			else
			{
				flag = 1;
			}
		}
		arr[k] = v;
	}
	return;
}

int main()
{
	int n;
	printf("Enter the number of elements to be entered : ");
	scanf("%d", &n);
	int arr[n + 1];
	printf("Enter the array : ");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("The array entered is : ");
	for (int i = 1; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	heapify(arr, n);
	printf("\nThe heap is : ");
	for (int i = 1; i < n + 1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}