#include<iostream>

using namespace std;

int main()
{

int a[30],i=0,key,h1,h2,n;

for(i=0;i<30;i++)
{
a[i]=0;
}

cout<<"enter no. of elements you want to insert"<<endl;
cin>>n;

for(i=0;i<n;i++)
{
cout<<"enter element"<<endl;
cin>>key;

h1=1+(key%(n-1));
if(a[h1]==0)
{
a[h1]=key;
}

else if(a[h1]!=0)
{
h2=29-(key%29);
a[h2]=key;

}
}

cout<<"-----------------------HASHING TABLE---------------------------"<<endl;
cout<<"\t\t\tkey\t\t\taddress"<<endl;
for(i=0;i<30;i++)
{
if(a[i]!=0)
{
cout<<"\t\t\t"<<a[i]<<"\t\t\t"<<i<<endl;
}
}

return 0;
}
