#include <stdio.h>
#include <stdlib.h>

void solve(int mat[][200], int n);
int fact(int n);

int main()
{
	int n;
	printf("Enter the number of people : ");
	scanf("%d", n);
	int mat[n][n];
	printf("Enter the cost matrix : ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	solve(mat, n);
	return 0;
}

void solve(int mat[][200], int n){
	for (int i = 0; i < fact(n); i++){
		
	}
}

int fact(int n){
	int res = 1;
	for(int i = 1; i<=n; i++){
		res *= i;
	}
	return res;
}