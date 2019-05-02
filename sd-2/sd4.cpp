#include<iostream>
#include<stack>

using namespace std;

char ver[15],v;char a,b;
int g[15][15],n,i=0,j=0,k=0,p,q;
bool vst[15];


int search(char a)
{
for( k=0;k<n;k++)
{
if(ver[k]==a)
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

cout<<"enter no. of vertices"<<endl;
cin>>n;

cout<<"enter no. of vertices in alphabeticasl order"<<endl;

for( i=0;i<n;i++)
{
cin>>ver[i];
}

int ne=0;

cout <<"enter no. of edges"<<endl;
cin>>ne;

for(i=0;i<ne;i++) 
{
cout<<"enter edge"<<endl;
cin>>a>>b;
p=search(a);
q=search(b);
cout<<"enter weight"<<endl;
cin>>g[p][q];
g[q][p]=g[p][q];

}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cout<<g[i][j]<<"\t";
}

cout<<"\n";
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

cout<<"enter vertex for PRIMS"<<endl;
cin>>v;


p=search(v);
vst[p]=true;



int temp=999;
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
cout<<ver[p]<<"--"<<g[p][q]<<"--"<<ver[q]<<"\t";
temp=999;

}



}




int main()
{
prims();

return 0;

}


