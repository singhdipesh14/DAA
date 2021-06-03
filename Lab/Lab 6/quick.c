#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int *arr, int left, int right, int *opcount)
{
	int start = left + 1;
	int pivot = left;
	int end = right;
	for (;;)
	{
		while (arr[start] <= arr[pivot])
		{
			(*opcount)++;
			start++;
		}
		(*opcount)++;
		while (arr[end] > arr[pivot])
		{
			(*opcount)++;
			end--;
		}
		(*opcount)++;
		if (start >= end)
		{
			break;
		}
		swap(arr, start, end);
	}
	swap(arr, pivot, end);
	return end;
}

void quick(int *arr, int left, int right, int *opcount)
{
	if (left < right)
	{
		int part = partition(arr, left, right, opcount);
		quick(arr, left, part - 1, opcount);
		quick(arr, part + 1, right, opcount);
	}
}

int main()
{
	printf("Enter the number of elements in the array : ");
	int num;
	scanf("%d", &num);
	printf("Enter the array : ");
	int *arr = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Your array is : ");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int opcount = 0;
	quick(arr, 0, num - 1, &opcount);
	printf("Your sorted array is : ");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nThe number of operations is  : %d\n", opcount);
	return 0;
}