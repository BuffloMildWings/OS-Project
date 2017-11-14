#include<iostream>
#include<conio.h>
#include <random>
#include "Deallocate.h"

using namespace std;
int main()
{
	int mem[128],processes,n1,n2,flags[10],allocation[10];  //N1 Number of partitions ad N2 number of processes 10,000
	int i,j;
    bool allocation;
//	clrscr();
	for(i=0;i < 10;i++)
	{
		flags[i]=0;
		allocation[i]=-1;
	}
	cout<<"\n enter no. of memory partitions: ";
	cin>>n1;
	cout<<"\n Enter size of each partition:";
	for(i=0;i < n1;i++)
		cin>>mem[i];
	cout<<"\n enter no. of processes :";
	cin>>n2;
	cout<<"\n Enter size of each process:";
	for(i=0;i < n2;i++)
		cin>>processes[i];
	//allocation as per first fit
	for(i=0;i < n2;i++)
		for(j=0;j < n1;j++)
			if(flags[j]==0 && mem[j]>=processes[i])
			{
				allocation[j]=i;
				flags[j]=1;
				break;
			}
	//display allocation details
	cout<<"\n partiton   size   process no.   size";
	for(i=0;i < n1;i++)
	{
		cout<<"\n"<<i<<"       "<<mem[i]<<"        ";
		if(flags[i]==1)
			cout<<allocation[i]<<"     "<<processes[allocation[i]];
		else
			cout<<"-------";
	}
	getch();
    return 0;
}
