#include<iostream>
using namespace std;

int i=0,j=0,k=1,n=0,a[30];
//-------------------------------------------------------------------------------------------------
inline void get(int a[30])
{cout<<"enter size of set"<<endl;
cin>>a[0];
cout<<"enter elements"<<endl;

for(i=1;i<=a[0];i++)
{cin>>a[i];


}}

//------------------------------------------------------------------------------------------------
void display(int a[30])
{
cout<<"your set is ";
for(i=1;i<=a[0];i++)
{
cout<<a[i]<<"\t";
}
cout<<endl;
}

//------------------------------------------------------------------------------------------------

void remove()
{int temp;
get(a);
cout<<"ENTER ELEMENT TO remove"<<endl;
cin>>temp;
for(i=1;i<=a[0];i++)
{
if(temp==a[i])
{
a[i]=0;

break;
}
}

while(i<a[0])
{
a[i]=a[i+1];
i++;
}
a[0]=a[0]-1;

display(a);


}

//---------------------------------------------------------------------------------------------------
inline void add()
{
get(a);
cout<<"ENTER ELEMENT TO INSERT"<<endl;
cin>>a[i];
a[0]=i;
display(a);
}




//------------------------------------------------------------------------------------------------
void search()
{
int temp;
get(a);
cout<<"Enter element to search "<<endl;
cin>>temp;

for(i=1;i<=a[0];i++)
{
if(temp==a[i])
{cout<<"TRUE"<<endl;
break;
}


}

if(temp!=a[i])
{
cout<<"false"<<endl;
}

}

//------------------------------------------------------------------------------------------------

void intesection (int a[30] , int b[30] , int c[30])
{
get(a);       //get two set
get(b);
display(a);
display(b);


for(i=1; i<=a[0] ; i++)   //finding common element 
{
for(j=1 ; j<=b[0] ; j++)
{
if(a[i]==b[j])
{
c[k]=a[i];
k++;

}
}c[0]=k-1;
}

if(k==1)
{cout<<"no intercestion"<<endl;
}
else {cout<<"intersection of sets is"<<endl;
display(c);
}
}

//------------------------------------------------------------------------------------------------


void unin(int a[30] , int b[30] ,int c[30])
{
int l=0;
get(a);       //get two set
get(b);
display(a);
display(b);
k=1;
for(i=1;i<=a[0];i++)
{
c[k]=a[i];
k++;}

for(i=1;i<=b[0];i++)
{l=0;
for(j=1;j<=a[0];j++)
{
if(b[i]!=a[j])
{
l++;
}

}
if(l==a[0])
{
c[k]=b[i];
k++;}

c[0]=k-1;
}

cout<<c[0];
cout<<"your union of two set is "<<endl;
display(c);

}

void size()
{
add();
cout<<"size of set is :\t"<<a[0]<<endl;
}
//------------------------------------------------------------------------------------------------
void subtract(int a[30] , int b[30] ,int c[30])
{
int l=0;
cout<<"enter the main set "<<endl;
get(a);
cout<<"enter set to subtarct "<<endl;
get(b);

k=1;
for(i=1;i<=a[0];i++)
{l=0;
for(j=1;j<=b[0];j++)
{
if(a[i]!=b[j])
{
l++;
}
}
if(l==b[0])
{
c[k]=a[i];
k++;
}
}
c[0]=k-1;

cout<<"your resultant set is "<<endl;
display(c);
}

//------------------------------------------------------------------------------------------------

void subset(int a[30] , int b[30])
{
cout<<"enter the bigger set "<<endl;
get(a);
cout<<"enter smaller set  "<<endl;
get(b);


cout<<" the 1st set "<<endl;
display(a);
cout<<" 2nd set  "<<endl;
display(b);

k=0;

for(i=1 ;i<=b[0] ;i++)
{
for(j=1;j<=a[0]; j++)
{
if(b[i]==a[j])
{k++;
}
}
}
if(k==b[0])
{
cout<<"2nd set is subset of 1st set"<<endl;
}
else
{
cout<<"2nd set is not subset of 1st set"<<endl;
}

}



//------------------------------------------------------------------------------------------------

int main ()
{
cout<<"enter your choise \n1.intersection\n2.union \n 3.subtract\n4.subset\n5.add lement\n6.remove\n7.search\n8.size \n9.exit"<<endl;
cin>>n;
int s1[30],s2[30],res[30];
switch(n)
{
case 1 :intesection(s1,s2,res);
	return main();

case 2 :unin(s1,s2,res);
	return main();
case 3 :subtract (s1,s2,res);
	return main();

case 4 :subset(s1,s2);
	return main();
case 5 : add();
 	return main();
case 6 : remove();
	return main();
case 7 :search();
	return main();
case 8 :size();
	return main();
case 9 :break;
}
return 0;
}
