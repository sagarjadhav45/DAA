#include<iostream>
#include<stdio.h>
using namespace std;

int c=0,cost=999;

int graph[4][4]={{0,20,49,52},{20,0,56,88},{68,89,0,77},{66,28,74,0}};

void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void copyarray(int *a,int n)
{
int i,sum = 0;
for(i=0;i<=n;i++)
{
sum +=graph[a[ i % 4]][a[( i + 1 ) % 4]];
}

if(cost>sum)
{
	cost=sum;
}

}
void permute(int *a,int i,int n)
{
int j,k;
if(i==n)
{
copyarray(a,n);
}
else
{
for(j=i;j<=n;j++)
{
swap((a+1),(a+j));
permute(a,i+1,n);
swap((a+1),(a+j));
}
}
}

int main()
{
int i,j;
int a[]={0,1,2,3};
permute(a,0,3);
cout<<"Mininum Cost for TSP is :- "<<cost<<endl;
}
 
