#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int *op)
{
	if (n <= 1)
	{
		return;
	}
	if (arr[n] > arr[n / 2])
	{
		(*op)++;
		int temp = arr[n];
		arr[n] = arr[n / 2];
		arr[n / 2] = temp;
	}
	heapify(arr, n / 2, op);
}

int insert(int arr[], int n, int val, int *op)
{
	n = n + 1;
	arr[n] = val;
	heapify(arr, n, op);
	return n;
}

int main()
{
	int arr[100];
	int choice = 0, ele;
	int n = 0;
	int opcount = 0;
	while (choice < 4)
	{
		printf("Enter your choice : 1)Insert Element 2)Display Heap 3)Display opcount 4)Exit\n : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the element : ");
			scanf("%d", &ele);
			n = insert(arr, n, ele, &opcount);
			break;
		case 2:
			printf("The heap is : ");
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;
		case 3:
			printf("The opcount for %d insertions is %d\n", n, opcount);
		case 4:
			continue;
			break;
		default:
			printf("Wrong choice entered, enter again\n");
		}
	}
	return 0;
}