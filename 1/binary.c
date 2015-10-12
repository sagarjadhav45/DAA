#include<stdio.h>
//#include<conio.h>

int i,j,flag,low,high,mid,x,n,a[20];

void sort(int a[],int n); //prototype

void accept()
{
 printf("\nHow many elements u want to enter in array:");
 scanf("%d",&n);
 printf("\n\nEnter Numbers in the array:");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
  sort(a,n);
 printf("\n\nEnter Element you want to search:");
 scanf("%d",&x);
 low=0;high=n;
}//end accept

void sort(int a[],int n)
{              //bubble sort
 int temp;
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
   {
     if(a[i]>a[j])
     {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
     }
   }
 }
 printf("\n\nSorted elements are: ");
 for(i=0;i<n;i++)
 printf(" %d",a[i]);
}//end sort


void binary(int a[],int low, int high, int x)
{
 int mid=(low+high)/2;
 if(low<high)
 {
  if(x<a[mid] && low!=high)
  {
   high=mid;
   binary(a,low,high,x);
  }
  else if(x>a[mid] && low!=high)
  {
   low=mid+1;
   binary(a,low,high,x);
  }
  else if(x==a[mid])
  { flag=1;
   printf("\n\nElement--> %d is found at location-->%d",x,mid+1);
  }
 }//end outer if
}//end binary

int main()
{
 int ch;
 //clrscr();
 do
 {
  flag=0;
  accept();
  binary(a,low,high,x);
  if(flag==0)
   printf("\nElement: %d is not found......",x);

  printf("\n Do you want to continue(1/0):");
  scanf("%d",&ch);
 }while(ch==1);
  //getch();
}//end main
