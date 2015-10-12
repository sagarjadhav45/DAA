//tested OK.
//Assignment no:3
//Implementation of kmean algorithm

#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
//#include<conio.h>

class kmean
{
 private:int k,n,prev[10],cluster[10];
	 float x[10],y[10],cx[10],cy[10],totalx,totaly,dist[10];
 public: void accept();
	 void mean();
	// void display();
};
int i,j;
void kmean::accept()
{
	cout<<"\nEnter Number of cluster: ";
	cin>>k;
	cout<<"\nEnter number of objects : ";
	cin>>n;
	cout<<"\nEnter objects values : \n";
	//enter objects values
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	//entering centroid for each cluster
	for(i=0;i<k;i++)
	{
		cout<<"\nEnter  "<<i+1<<"  centroid : ";
		cin>>cx[i]>>cy[i];
	}
	//initially consider all objects in one cluster
	for(i=0;i<n;i++)
	 cluster[i]=0;

}//end accept

void kmean::mean()
{
  int min,ch;
 do
 {
  ch=0; //ch is used for iteration purpose
  for(i=0;i<n;i++)      //set prev cluster no.
   prev[i]=cluster[i];  //intially it is=0.
  cout<<"\n objects\t";
  for(i=0;i<k;i++)
   cout<<"\t"<<"C"<<i+1<<"["<<cx[i]<<"]["<<cy[i]<<"]";
  cout<<"\tcluster";
  cout<<"\n----------------------------------------------------------------------";
  for(j=0;j<n;j++)//loop for n objects
  {
   min=9999;
   cout<<"\nX"<<j+1<<"["<<x[j]<<"]["<<y[j]<<"] \t";
   for(i=0;i<k;i++)//loop for centroids
   {
    dist[i]=abs((x[j]-cx[i]));        //calculate distance by using formula
    dist[i]=dist[i]+abs((y[j]-cy[i])); //dist=|X-Cx|+|Y-Cy|
    if(dist[i]<min)            //find min distance
    {
     min=dist[i];
     cluster[j]=i;     // assign object to corressponding cluster
    }
    cout<<"\t"<<dist[i]<<"\t";
   }//end inner for
    cout<<"\t"<<cluster[j]+1;
  }//end outer for

  //assign new coordinates to centroid
  int cnt;
  for(i=0;i<k;i++)
  {
   cnt=0,totalx=0,totaly=0;
   cout<<"\n\n Cluster:"<<i+1;
   cout<<"\n============\n";
   for(j=0;j<n;j++)
   {
     if(cluster[j]==i)  //display objects clustering
     {
      cnt++;
      cout<<"\nX"<<j+1<<"["<<x[j]<<"]["<<y[j]<<"]";
      totalx+=x[j];  //totalx=totalx+x[j];
      totaly+=y[j];
     }
   }
    cx[i]=totalx/cnt;     //new coordinates of centroid
    cy[i]=totaly/cnt;
  }//end for

  for(i=0;i<n;i++)
  {
   if(prev[i]==cluster[i])   //if previous and current cluster no. are same
     continue;              //then exit
   else if(prev[i]!=cluster[i])  //if there is change in cluster no.
   {                            //continue clustering again for
     ch=1;                      //that make ch=1
   }
  }
 }while(ch==1);
}//end mean

int main()
{
 //clrscr();
 kmean k;
 k.accept();
 k.mean();
 //getch();
}
