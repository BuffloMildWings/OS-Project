
#include<iostream>

#define MAX_SIZE 128
#define TEST_SIZE 100

using namespace std;


class memory
{
    public:
        memory();
        void allocate_mem();
        int allocate_mem_ff(int process_id, int num_units);
        int deallocate_mem (int process_id);
        int fragment_count();
        void print_mem();



    private:
        void init_processes();
        void init_allocation();
        int psize[TEST_SIZE];
        int allocation[MAX_SIZE];
        int fragments;

};
memory::memory(){
    init_processes();
    init_allocation();
    fragments=0;
}
//computing processes sizes between 3 and 10 units
void memory::init_processes(){
    for(int i=0;i<=TEST_SIZE;i++)
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
//    cout<<"CT is "<<ct<<endl;
//    cout<<"Process ID is "<<process_id<<endl;
    for(int start=0;start<=MAX_SIZE-num_units;start++) {
//        cout<<"Start is "<<start<<endl;
        if (allocation[start] == 0) {
            for (int j = (start + 1); j < MAX_SIZE; j++){
              if (allocation[j] == 0 && ct != 0) {
                 ct--;
            } else if (allocation[j] != 0) {
                start = j;
                ct = num_units;
//                cout<<"Is this updated?"<<endl;
            } else if (ct == 0 && allocation[j] == 0) {
                for (int k = start; k < start + num_units; k++) {
                    allocation[k] = process_id;
//                    cout<<"Process "<<allocation[k]<<" is stored in Memory Block "<< k <<endl;
                }
                return 1;
            } else {
//                  cout<<"Failed ";
                 return -1;
            }
            }
        }
    }
//    cout<<"Failed and Finished loop"<<endl;
    return -1;
}


void memory::allocate_mem(){

    int temp;
    int del=1;
for (int i=0;i<TEST_SIZE;i++)
{
    temp = psize[i];
    while(allocate_mem_ff(i+1,temp)==-1){
        if(deallocate_mem(del)==1) {
            del++;
        }
    }
}

}

int memory::deallocate_mem(int process_id){
    int i=0;
    bool rem_flag=false;
    while(i<MAX_SIZE){
        if(rem_flag ||allocation[i]==process_id){
            rem_flag=true;
            allocation[i]=0;
            if(allocation[i+1]!=process_id){
                return 1;
            }

        }
        i++;
    }
    return -1;

}

void memory::print_mem() {
    for(int i=0;i<MAX_SIZE-6;++i){
        cout<<allocation[i]<<" "<<allocation[i+1]<<" "<<allocation[i+2]
            <<" "<<allocation[i+3] <<" "<<allocation[i+4]<<" "<<allocation[i+5]
            <<" " <<allocation[i+6] <<" "<<allocation[i+7]<<endl;
        i=i+7;
    }
    cout<<"There is "<<fragment_count()<<" fragments in memory."<<endl;
}

int memory::fragment_count() {
    int check;
    fragments=0;
    check=0;
    for(int i=0;i<MAX_SIZE;i++){
        if(allocation[i]==0){
            check++;
        } else if(check<3){
            fragments++;
        }
        check=0;
    }
}