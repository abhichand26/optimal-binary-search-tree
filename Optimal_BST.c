#include<stdio.h>
#include<stdlib.h>
#define N 20
#define inf 9999

/*
** Program to implement Optimal Binary Search Tree using Dynamic Programming
** Made by - Abhishek Chand
*/


float W[N][N],E[N][N],R[N][N],P[N];

void OptimalBST(int n)
{
	int i,j,r,l;
	float q;
	for(i=1;i<=n+1;i++)
	{
		E[i][i-1]=0;
		W[i][i-1]=0;
	}
	
	for(l=1;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			j=i+l-1;
			W[i][j]=W[i][j-1]+P[j];
			E[i][j]=inf;
			for(r=i;r<=j;r++)
			{
				q=E[i][r-1]+E[r+1][j]+W[i][j];
				if(q<E[i][j])
				{
					E[i][j]=q;
					R[i][j]=r;
				}
			}
		}
	}
}

int main()
{
	int i,j,n;
	float sum=0;
	printf("Enter the no. of keys:");
	scanf("%d",&n);
	do
	{
		printf("\nEnter the probabilities of keys:");
		for(i=1;i<=n;i++)
		{
			scanf("%f",&P[i]);
			sum+=P[i];
		}
		if(sum==1)
			break;
		else
			printf("\nEnter the correct set of probabilities");
	}while(sum!=1);
	OptimalBST(n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%.2f\t",E[i][j]);
		}
		printf("\n");
	}
	return 0;
}
