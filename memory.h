
#include<iostream>

using namespace std;


class memory
{
    public:
        memory();
        void allocate_mem();
        int allocate_mem_ff(int process_id, int num_units);
        int deallocate_mem (int process_id);
        int fragment_count();
        void init_processes();
        void init_allocation();


    private:

      int psize[1000];
       int allocation[128];

};

//computing processes sizes between 3 and 10 units
void init_processes(){
    for(int i=1;i<=1000;i++)
    {
       if (i%3==3)
            psize[i]=3;
        else if(i%4==4)
            psize[i]=4;
        else if(i%5==5)
            psize[i]=5;
        else if(i%6==6)
            psize[i]=6;
        else if(i%7==7)
            psize[i]=7;
        else if(i%8==8)
            psize[i]=8;
        else if(i%9==9)
            psize[i]=9;
        else
            psize[i]=10;
    }

}

void init_allocation(){
    for(i=0;i<nb;i++) //initialize memory array
{
    allocation[i]=0;
}

}

int allocate_mem_ff(int process_id, int num_units){
int ct=num_units; //counting free blocks in a row
for(int i= 0;i<128;i++)
    if(allocation[i]==0)
    {
    start=i;
    for(int j=(start+1);j<128;j++)
        if(allocation[j]==0 && ct!=0)
            ct--;
        else if(allocation[j]!=0)
            start=j;
            ct=num_units;
        else if (ct==0)
            for(int k=start;k<num_units;k++)
               {
                   allocation[k]=process_id;
               }
            return 1;
        else return -1
    }

    else return -1;

}



void allocate_mem(){

int temp;
for (i=1;i<=1000;i++)
{
    temp = psize[i-1];
    allocate_memff(i,temp);
}

}
