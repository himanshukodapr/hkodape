#include<iostream>

using namespace std;

int temp,j=0,a[50];
//-------------------------------------------------------------------------------------------------
inline void show(int a[50],int n)
{

for(j=0;j<n;j++)
{
cout<<a[j]<<"\t";

}

cout<<endl;

}
//----------------------------------------------------------------------------------------------
 inline void minheap(int a[50],int n)

{


j=0;
while(j<n)
{


if (a[j]>a[(2*j) + 1])
{

temp=a[j];
a[j]=a[j+j+1];
a[j+j+1]=temp;

j=0;
}


else if(a[j]>a[(2*j)+2] )
{

temp=a[j];
a[j]=a[j+j+2];
a[j+j+2]=temp;
j=0;
}

else
{

j++;}

}
show(a,n);
cout<<"MIN. SCORE OF STUDNETS IN MATH"<<endl;
cout<<a[0]<<endl;
}
//-------------------------------------------------------------------------------------------------
inline void maxheap(int a[50] ,int n)
{


j=0;

while(j<n)
{


if (a[j]<a[(2*j) + 1] && a[j]!=9999 && a[j+j+1]!=9999)
{

temp=a[j];
a[j]=a[j+j+1];
a[j+j+1]=temp;

j=0;
}


else if(a[j]<a[(2*j)+2] && a[j+j+2]!=9999)
{

temp=a[j];
a[j]=a[j+j+2];
a[j+j+2]=temp;
j=0;
}

else
{

j++;

}

}

show(a,n);

cout<<"MAX SCORE OF STUDNETS IN MATH"<<endl;
cout<<a[0]<<endl;

}
//-------------------------------------------------------------------------------------------------
inline void insert(int key,int n)
{
cout<<"enter marks to insert"<<endl;
cin>>key;
a[n]=key;
n=n+1;
for(j=0;j<n;j++)
{
cout<<a[j]<<"\t";

}

cout<<endl;
minheap(a,n);


}
//-------------------------------------------------------------------------------------------------

inline void pop(int a[50] , int n)
{

a[0]=999;

for(j=1;j<n;j++ )
{
a[j-1]=a[j];

}
n=n-1;
minheap(a,n);
}

int main()
{

int no;
int temp;
int n;


for(j=0;j<50;j++)
{

a[j]=9999;}

cout<<"enter no. of studnet "<<endl;
cin>>n;

cout<<"enter marks obtained in math out of 50"<<endl;

for(j=0;j<n;j++)
{
cin>>a[j];

}

minheap(a,n);
maxheap(a,n);
insert(no,n);
n++;
insert(no,n);
n++;
for(j=0;j<n;j++)
{
cout<<a[j]<<"\t";

}

pop(a,n);
n--;

for(j=0;j<n;j++)
{
cout<<a[j]<<"\t";

}

return 0;
}

