//#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const size = sizeof(int);
int n;

fill(int**);
det(int**, int);
print(int**);

main()
{
	int **matrix;
	printf("enter n: ");
	scanf("%d", &n);
	matrix = malloc(sizeof(int*) * n);
	//init 
	for (int i = 0; i < n; i++)
	{
		matrix[i] = malloc(size * n);
	}
	fill(matrix);
	print(matrix);
	printf("det = %d\n", det(matrix, n));
	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}
fill(int **matrix)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 11;
	return 0;
}
print(int **matrix)
{
	for (int i = 0; i < n; i++, printf("\r\n"))
		for (int j = 0; j < n; j++)
			printf("%d\t", matrix[i][j]);
}
int** minor(int** matrix, int row, int n)
{
	int **res = malloc(sizeof(int*) * (n - 1));
	for (int i = 0; i < n; i++)
	{
		if (i == row)
			continue;
		int k = i < row ? i : i - 1;
		res[k] = matrix[i] + 1;
	}
	return res;
}
parity(x)
{
	return x % 2 ? -1 : 1;
}
det(int **matrix, int n)
{
	if (n == 1)
		return matrix[0][0];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int** m = minor(matrix, i, n);
		sum += parity(i) * (matrix[i][0]) * det(m, n - 1);
		free(m);
	}
	return sum;
}
