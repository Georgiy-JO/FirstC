#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

/*
int factor(int a, int b)
{
	if (a == 0 || a == 1)
		return 1;
	else
	{
		int temp = a * factor((a - 1), b);
		if (temp % b == 0)
			return b;
		else
			return (temp % b);
	}
	//return a==0 || a==1? 1: (a*(factor((a-1), b))%b);
}
*/
/*
int binom(int m, int n, int k)
{
	if (k<0 || k>n)
		return 0;
	else
	{
		int** matrix = (int**)calloc(n + 1, sizeof(int*));
		for (int i = 0; i < n + 1; i++)
		{
			matrix [i] = (int*)calloc((i + 1), sizeof(int));
			matrix[i][0] = 1;
			matrix[i][i] = 1;
		}

		
		for (int i = 2; i < n + 1; i++)
		{
			for (int j = 1; j < i; j++)
			{
				matrix[i][j] = (matrix[i - 1][j - 1] + matrix[i - 1][j]);
				if (matrix[i][j] >= m)
					matrix[i][j] %= m;
				//if (i == n && j == k)
				//	return matrix[i][j];
			}
			free(matrix[i - 1]);
		}
		return matrix[n][k];
	}
}
*/
/*
int binom(int m, int n, int k)
{
	int res = 1;
	if (k<0 || k>n)
		res = 0;
	else
	{
		int temp = 1;
		if (n - k > k)
		{
			for (int i = n - k + 1; i <= n; i++)
			{
				res *= i;
				if (res % m == 0)
					res = m;
				else
					res = res % m;
			}
			for (int i=1; i <= k; i++)
			{
				temp *= i;
				if (temp % m == 0)
					temp = m;
				else
					temp = temp % m;
			}
			
			res /= temp;
			res %= m;

		}
		else
		{
			for (int i = k + 1; i <= n; i++)
			{
				res *= i;
				if (res % m == 0)
					res = m;
				else
					res = res % m;
			}
			for (int i = 1; i <= (n-k); i++)
			{
				temp *= i;
				if (temp % m == 0)
					temp = m;
				else
					temp = temp % m;
			}
			//printf("%d", temp);
			res /= temp;
			res %= m;

		}
	}
	return res;
} 
*/
/*
int binom(int m, int n, int k)
{
	int res = 0, up, down1, down2;
	if (k<0 || k>n)
		res = 0;
	else
	{
		up = factor(n, m);
		down1 = factor(k, m);
		down2 = factor((n - k), m);
		if (up == 0)
			up += m;
		if (down1 == 0)
			down1 += m;
		if (down2 == 0)
			down2 += m;
		//printf("-->%d %d %d->", up, down1, down2);
		while (!0)
		{
			if (up / down1 / down2 < (float)up / (float)down1 / (float)down2)
				up += m;
			else
				break;
		}
		//printf("%d %d %d-->", up, down1, down2);
		res = up / down1 / down2;
		res %= m;
	}
	return res;
}
*/


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int M, T, max=0;
	
	scanf("%d %d", &M, &T);
	int* n = (int*)calloc(T, sizeof(int));
	int* k = (int*)calloc(T, sizeof(int));
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &n[i], &k[i]);
		if (n[i] > max)
			max = n[i];
	}

	int** matrix = (int**)calloc(max + 1, sizeof(int*));
	for (int i = 0; i < max + 1; i++)
	{
		matrix[i] = (int*)calloc((i + 1), sizeof(int));
		matrix[i][0] = 1;
		matrix[i][i] = 1;
	}
	for (int i = 2; i < max + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			matrix[i][j] = (matrix[i - 1][j - 1] + matrix[i - 1][j]);
			if (matrix[i][j] >= M)
				matrix[i][j] %= M;
		}
	}
	for (int i = 0; i < T; i++)
	{
		if (k[i]<0 || k[i]>n[i])
			printf("%d\n", 0);
		else
			printf("%d\n", matrix[n[i]][k[i]]);
	}
	return 0;
}