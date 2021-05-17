#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int arr[], int n);
int swap(int arr[], int i, int j);

int main()
{
	int n;
	printf("Enter the number of elements in the array : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the elements : ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int count = bubbleSort(arr, n);
	printf("The array after sorting is : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nThe number of operations are : %d\n", count);
	return 0;
}

int bubbleSort(int arr[], int n)
{
	int cnt = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				cnt++;
				swap(arr, j, j + 1);
			}
		}
	}
	return cnt;
}

int swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}