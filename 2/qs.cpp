//Assignment no:2
//Aim:Write a C++ program to sort the array elements using quick sort.
//Status:Tested OK...

#include<iostream>
//#include<conio.h>
using namespace std;

class Quick
{
 public:
	int n,l,h,i,low,high,a[20];
	void accept();
	void display();
	int partition(int low,int high,int *a);
	void quick(int l,int h,int *a);
}qs;

void Quick::accept()
{
 cout<<"Enter how many elements u want to enter:";
      cin>>n;
      cout<<"Enter the elements:";
      for(i=0;i<n;i++)
      cin>>a[i];
      l=0;
      h=n-1;
   cout<<"\nInitial Array:\n";
      for(i=0;i<n;i++)
      {
       cout<<a[i]<<" ";
      }
}

void Quick::display()
{
 cout<<"\n\nAfter Sorting by Quick Sort:\n";
      for(i=0;i<n;i++)
      {
       cout<<a[i]<<" ";
      }
      cout<<"\n";
}
//Function for partitioning array
int Quick::partition(int low,int high,int *a)
{
     int h=high,l=low,p,t;  //p==pivot
     p=a[low];
     while(low<high)
     {
		    while(a[l]<p)
		    {
		     l++;
		    }
		    while(a[h]>p)
		    {
		     h--;
		    }
		    if(l<h)    //if l<h then swap a[l] and a[h]
		    {
		     t=a[l];
		     a[l]=a[h];
		     a[h]=t;
		    }
		    else // if l is not less than h then swap pivot and a[l]
		    {
			t=p;
			p=a[l];
			a[l]=t;
			break;
		    }
     }//end while
     return h;   //return h for further partitioning
}

void Quick::quick(int l,int h,int *a)
{
  int index,i;
  if(l<h)
  {
	  index=partition(l,h,a);
	  quick(l,index-1,a);
	  quick(index+1,h,a);
  }
}

int main()
{
    //  clrscr();
      Quick q;
      q.accept();
      q.quick(q.l,q.h,q.a);
      q.display();
     // getch();

}




