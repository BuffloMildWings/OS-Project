
#include<iostream>

#define MAX_SIZE 128

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

      int psize[10000];
       int allocation[MAX_SIZE];

};
memory::memory(){
    init_processes();
    init_allocation();
}
//computing processes sizes between 3 and 10 units
void memory::init_processes(){
    for(int i=0;i<=10000;i++)
    {
        psize[i]=rand()%8+3;
//        std::cout<<"Process size is "<<psize[i]<<std::endl;
    }

}

void memory::init_allocation(){
    for(int i=0;i<MAX_SIZE;i++) //initialize memory array
{
    allocation[i]=0;
}

}

int memory::allocate_mem_ff(int process_id, int num_units){
    int ct=num_units; //counting free blocks in a row
    cout<<"CT is "<<ct<<endl;
    cout<<"Process ID is "<<process_id<<endl;
    for(int start=0;start<=MAX_SIZE-num_units;start++) {
        cout<<"Start is "<<start<<endl;
        if (allocation[start] == 0) {
            for (int j = (start + 1); j < MAX_SIZE; j++){
              if (allocation[j] == 0 && ct != 0) {
                 ct--;
            } else if (allocation[j] != 0) {
                start = j;
                ct = num_units;
                cout<<"Is this updated?"<<endl;
            } else if (ct == 0 && allocation[j] == 0) {
                for (int k = start; k < num_units; k++) {
                    allocation[k] = process_id;
                }
                  cout<<"Inserted "<<process_id<<" into Memory chunk "<<start<<endl;
                return 1;
            } else {
                  cout<<"Failed ";
                 return -1;
            }
            }
        }
    }
    cout<<"Failed and Finished loop"<<endl;
    return -1;
}


void memory::allocate_mem(){

int temp;
for (int i=0;i<100;i++)
{
    temp = psize[i];
    allocate_mem_ff(i+1,temp);
}

}
