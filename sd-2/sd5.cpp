#include<iostream>
#include<string>

using namespace std;

char ver[15];string a,b;
int g[15][15],n,i=0,j=0,k=0,p,q;
bool vst[15];
string s[15],v;

int search(string c)
{
for( k=0;k<n;k++)
{
if(s[k]==c)
{
return k;
}
}

}

inline void graph()
{

for( j=0;j<15;j++)

{
vst[j]=false;
}

for( i=0;i<15;i++)
{

for( j=0;j<15;j++)

{
g[i][j]=0;
}


}

cout<<"enter no. of OFFICES "<<endl;
cin>>n;

cout<<"ENTER NAME OF CITIES"<<endl;

for( i=0;i<n;i++)
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
cout<<"Enter COST REQUED FOR SETUP OF PHONE LINE(IN k Rs)"<<endl;
cin>>g[p][q];
g[q][p]=g[p][q];
cout<<"do you want to enter another connection(y or n)"<<endl;
cin>>ch;
}


cout<<"OFFICE 1\tOFFICE 2\t\tCOST OF PHONE LINE(IN k Rs)"<<endl;

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(g[i][j]!=0)
{
cout<<s[i]<<"\t"<<s[j]<<"\t\t\t"<<g[i][j]<<"\n";
}
}

}

}




int alltrue()
{int k=0;
for(i=0;i<n;i++)
{
if (vst[i]==true)
{
k++;
}
}
return k ;
}



void prims()
{ 

graph();

cout<<"ENTER CITY FOR SOURCE OF PHONE LINE SETUP"<<endl;
cin>>v;


p=search(v);
vst[p]=true;

cout<<"YOU SHOULD CHOOSE YOUR CONNECTION BETWEEN OFFICES MENTIONED AS BELOW"<<endl;
int sum=0;
int temp=9999;
while(alltrue()!=n)
{
for(i=0;i<n;i++)
{
if(vst[i]==true)
{
for(j=0;j<n;j++)
{
if(vst[j]==false && g[i][j]!=0)
{

if(temp>g[i][j])
{
temp=g[i][j];
p=i;q=j;
}
}
}
}
}

vst[q]=true;

cout<<s[p]<<"--"<<g[p][q]<<"--"<<s[q]<<"\t";
temp=999;
sum=sum+g[p][q];
}

cout<<"TOTAL COST FOR SETUP CONNECTION TO ALL OFIICES  IS :"<<sum<<"k Rs"<<endl;

}




int main()
{
prims();

return 0;

}


