#include<iostream>
#include<string>

using namespace std;



string s[30];
int i=0,ver,k,j=0;
double g[30][30];




int search( string c)
{
for( k=0;k<ver;k++)
{
if(s[k]==c)
{
return k;
}
}
}


 void graph()
{

int p,q;

string a,b;
for( i=0;i<30;i++)
{

for( j=0;j<30;j++)

{
g[i][j]=0;
}


}

cout<<"enter no. cities"<<endl;
cin>>ver;

cout<<"enter name of cities"<<endl;

for( i=0;i<ver;i++)
{
cin>>s[i];
}

char ch='y';




while(ch=='y' || ch=='Y')
{
cout<<"enter city 1 "<<endl;
cin>>a;
cout<<"enter city 2 "<<endl;
cin>>b;
p=search(a);
q=search(b);
cout<<"Enter TIME of required for travelling in HH.MM"<<endl;
cin>>g[p][q];
g[q][p]=g[p][q];
cout<<"do you want to enter another route(y or n)"<<endl;
cin>>ch;
}

cout<<"SOURCE\tDESTINATION\tTIME REQIRED(HH.MM)"<<endl;

for(i=0;i<ver;i++)
{
for(j=0;j<ver;j++)
{
if(g[i][j]!=0)
{
cout<<s[i]<<"\t"<<s[j]<<"\t\t\t"<<g[i][j]<<"\n";
}
}

cout<<"\n";
}

}


int main()
{
graph();
return 0;
}


