#include<iostream>
#include<string>
#include<list>
#include<iterator>
using namespace std;
//--------------------------------------------------------------------------------------------------------------------------------------------
	string s[8];
	int wl[8][2],a[8],qw[4],sw[2];
bool freez[8];
	int point[8],m=1;			// DECLARING VARIABLE,LIST,STRING
	list<char> l[8];

//--------------------------------------------------------------------------------------------------------------------------------------------
inline void creat()

{

		
		s[0]="MI";s[1]="CSK";s[2]="RCB";s[3]="KXIP";s[4]="RR";s[5]="SRH";s[6]="DC";s[7]="KKR";
 	 
	for(int i=0;i<8;i++)
	{
		point[i]=0;
	for(int j=0;j<2;j++)
	{
		wl[i][j]=0;
		}								
	}					//INITIALIZING ALL ARRAY ,VARIABLES,TEAM NAMES 
	
	for(int i=0;i<8;i++)
	{
	
	freez[i]=false;
	}
		
	for(int i=0;i<8;i++)
	{
	a[i]=i;
	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------
void heapify(int arr[8], int n, int i)
{
   
   int largest = i;
   int l = 2*i + 1;
   int r = 2*i + 2;

   if (l < n && point[arr[l]] < point[arr[largest]])
     largest = l;

   if (r < n && point[arr[r]] < point[arr[largest]])
     largest = r;

 
   if (largest != i)
   {
     swap(arr[i], arr[largest]);
     heapify(arr, n, largest);
   }								// SORTING ALGORITHM
}


void heapsort(int arr[8], int n)
{
  
   for (int i = n / 2 - 1; i >= 0; i--)
     heapify(arr, n, i);

 
   for (int i=n-1; i>=0; i--)
   {
     swap(arr[0], arr[i]);
     
     heapify(arr, i, 0);
   }
}
//-------------------------------------------------------------------------------------------------------------------------------------------
inline void update(int n,int s)
{
wl[n][0]=wl[n][0]+1;
wl[s][1]=wl[s][1]+1;
point[n]=point[n]+2;
l[n].push_back('W');
l[s].push_back('L');


}

//-------------------------------------------------------------------------------------------------------------------------------------------

inline char form(list<char>q)
{
for(auto it=q.begin();it!=q.end();++it)	// DISPALYING FORM OF EACH TEAM 
{
cout<<*it<<" ";
}
}


//-----------------------------------------------------------------------------------------------------------------------------------------

inline void round1()
{string w;
int k=0;
while(k<8)
{
cout<<" match\t"<<m<<":"<<s[k]<<" vs "<<s[k+1]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[k])
{
update(k,k+1);
k=k+2;
m++;
}

else if(w==s[k+1])	    				// ALGORITHM FOR ROUND 1

{

update(k+1,k);
k=k+2;
m++;
}

else
{
cout<<"wrong entry\n";
}
}

}

//---------------------------------------------------------------------------------------------------------------------------------------------

inline void round2()
{string w;
int k=0;
while(k<4)
{
cout<<" match\t"<<m<<":"<<s[k]<<" vs "<<s[k+4]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[k])
{
update(k,k+4);
k=k+1;
m++;
}

else if(w==s[k+4])			// ALGORITHM FOR ROUND 2

{

update(k+4,k);
k=k+1;
m++;
}

else
{
cout<<"wrong entry\n";
}
}

}

//--------------------------------------------------------------------------------------------------------------------------------------------

inline void round3()
{string w;
int k=0;
while(k<2)
{
cout<<" match\t"<<m<<":"<<s[k]<<" vs "<<s[k+2]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[k])
{
update(k,k+2);
k=k+1;
m++;
}

else if(w==s[k+2])

{

update(k+2,k);
k=k+1;
m++;
}

else
{
cout<<"wrong entry\n";
}
}

k=4;
while(k<6)
{
cout<<" match\t"<<m<<":"<<s[k]<<" vs "<<s[k+2]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[k])
{
update(k,k+2);
k=k+1;
m++;
}

else if(w==s[k+2])							// ALGORITHM FOR ROUND 3

{

update(k+2,k);
k=k+1;
m++;
}

else
{
cout<<"wrong entry\n";
}
}

}


//---------------------------------------------------------------------------------------------------------------------------------------------



inline void round4()
{
int a[4][2];

a[0][0]=0;a[0][1]=5;a[1][0]=2;a[1][1]=7;a[2][0]=3;a[2][1]=6;a[3][0]=1;a[3][1]=4;

string w;
int i=0,k=0,l=0;
while(i<4)
{
k=a[i][0];l=a[i][1];
cout<<" match\t"<<m<<":"<<s[k]<<" vs "<<s[l]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[k])
{
update(k,l);					// ALGORITHM FOR ROUND 4
i++;
m++;
}

else if(w==s[l])

{

update(l,k);
i++;
m++;
}

else
{
cout<<"wrong entry\n";
}
}

}

//----------------------------------------------------------------------------------------------------------------------------------------------
inline void qfinal()
{string w;
int k=0;
while(k<8)
{
cout<<" match\t"<<m<<":"<<s[k]<<" vs "<<s[k+1]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[k])
{

freez[k+1]=true;
update(k,k+1);					// ALGORITHM FOR QUATER FINAL
k=k+2;
m++;
}

else if(w==s[k+1])

{
freez[k]=true;
update(k+1,k);
k=k+2;
m++;
}

else
{
cout<<"wrong entry\n";
}
}

}

//---------------------------------------------------------------------------------------------------------------------------------------------

inline void sfinal()
{

string w;
int k=0,j=0;
int avl[4];

for(int i=0;i<8;i++)
{
if(freez[i]!=true)
{
avl[j]=i;
j++;
}


}

cout<<avl[0]<<endl;

k=0;
while(k<3)
{
cout<<" match\t"<<m<<":"<<s[avl[k]]<<" vs "<<s[avl[k+1]]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[avl[k]])
{

freez[avl[k+1]]=true;
update(avl[k],avl[k+1]);
k=k+2;
m++;
}

else if(w==s[avl[k+1]])		// ALGORITHM FOR SEMI FINALS

{
freez[avl[k]]=true;
update(avl[k+1],avl[k]);
k=k+2;
m++;
}

else
{
cout<<"wrong entry\n";
}
}


}

//----------------------------------------------------------------------------------------------------------------------------------------------


inline void finals()
{

string w;
int k=0,j=0;
int avl[2];

for(int i=0;i<8;i++)
{
if(freez[i]!=true)
{
avl[j]=i;
j++;
}


}

cout<<avl[0]<<endl;

k=0;
while(k<2)
{
cout<<" match\t"<<m<<":"<<s[avl[k]]<<" vs "<<s[avl[k+1]]<<"\nENTER WINNER\t";
cin>>w;

if(w==s[avl[k]])
{

freez[avl[k+1]]=true;							// ALGORITHM FOR SEMI FINALS
update(avl[k],avl[k+1]);
k=k+2;
m++;
}

else if(w==s[avl[k+1]])

{
freez[avl[k]]=true;
update(avl[k+1],avl[k]);
k=k+2;
m++;
}

else
{
cout<<"wrong entry\n";
}
}


}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 void show(int b[8],int n)
{

heapsort(b,n);

cout<<"-------------------------------IPL 2K19-------------------------------\n";
		cout<<"\tsr.no\tname\ttotal matches\twin\tloose\tpoints\tforms\n";
		for(int i=0;i<n;i++)
	{
		
cout<<"\t"<<i+1<<"\t"<<s[b[i]]<<"\t\t"<<wl[b[i]][0]+wl[b[i]][1]<<"\t";				// ALGORITHM FOR SHOW FUNCTION
cout<<wl[b[i]][0]<<"\t"<<wl[b[i]][1]<<"\t"<<point[b[i]]<<"\t"<<form(l[b[i]])<<endl;	
	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	cout<<"----------------------STARTING IPL 2019------------------------------\n\n";
		creat();

		show(a,8);
		cout<<"\n--------------------------------ROUND 1--------------------------------\n\n";
		round1();
		show(a,8);
cout<<"\n--------------------------------ROUND 2--------------------------------\n\n";
		round2();
		show(a,8);
cout<<"\n--------------------------------ROUND 3--------------------------------\n\n";
		round3();
		show(a,8);
		cout<<"\n--------------------------------ROUND 4--------------------------------\n\n";
		round4();
		show(a,8);
cout<<"\n---------------------QUATER FINAL(ELIMINATION ROUND)---------------------\n\n";
		qfinal();

int p=0,q=0;		
for(int i=0;i<8;i++)

{
if(freez[i]==false)
{
qw[p]=i;
p++;
}

}

cout<<"\n--------------------------------WINNNER TEAM--------------------------------\n\n";
		show(qw,4);
		
cout<<"\n--------------------------------SEMI FINAL--------------------------------\n\n";
		sfinal();
p=0;
for(int i=0;i<8;i++)

{
if(freez[i]==false)
{
sw[p]=i;
p++;
}

}	
cout<<"\n----------------------------WINNER OF SEMI FINALS---------------------------\n\n";
		show(sw,2);
cout<<" FINAL\n\n"<<endl;

cout<<"\n-----------------^^^^*******FINALS******^^^^---------------------\n\n";
		finals();

int fw[1];
p=0;
for(int i=0;i<8;i++)

{
if(freez[i]==false)
{
fw[0]=i;
}

}

cout<<"\n**********$$$$$$$$$$$^^^^WINNER TEAM OF IPL 2019^^^^$$$$$$$$$$$**********\n\n";	

		show(fw,1);

cout<<"\n--------------------------------FINAL SCOREBOARD--------------------------------\n\n";

		show(a,8);
return 0;	
}


