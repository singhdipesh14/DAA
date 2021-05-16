#include <stdio.h>
#include <stdlib.h>

int BFSM(char str[], char pat[], int n, int m, int* cnt);

int main()
{
	char str[100], pat[100];
	printf("Enter the string : ");
	char c;
	int cntA = 0;
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n')
		{
			str[cntA++] = '\0';
			break;
		}
		str[cntA++] = c;
	}
	int cntB = 0;
	printf("Enter the string to be searched : ");
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n')
		{
			pat[cntB++] = '\0';
			break;
		}
		pat[cntB++] = c;
	}
	printf("String : ");
	for (int i = 0; i < cntA; i++)
	{
		printf("%c", str[i]);
	}
	printf("\nPattern : ");
	for (int i = 0; i < cntB; i++)
	{
		printf("%c", pat[i]);
	}
	printf("\n");
	int cnt = 0;
	int res = BFSM(str, pat, cntA - 1, cntB - 1, &cnt);
	if (res == -1)
	{
		printf("The string is not found, the opcount is : %d\n", cnt);
	}
	else
	{
		printf("The string is found at index %d and the opcount is : %d\n", res, cnt);
	}
	return 0;
}

int BFSM(char str[], char pat[], int n, int m, int* cnt)
{
	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		while ((j < m) && (pat[j] == str[i + j]))
		{
			(*cnt)++;
			j++;
		}
		if (j == m)
			return i;
		(*cnt)++;
	}
	return -1;
}
