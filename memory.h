
#include<iostream>
#include <time.h>

#define MAX_SIZE 128
#define TEST_SIZE 100

using namespace std;


class memory
{
    public:
        memory();
        void allocate_mem(int mode);
        int allocate_mem_ff(int process_id, int num_units);
        int allocate_mem_nf(int process_id, int num_units);
        int allocate_mem_bf(int process_id, int num_units);
        int allocate_mem_wf(int process_id, int num_units);
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
   srand(time(NULL));
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
    for(int start=0;start<=MAX_SIZE-num_units;start++) {
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
    return -1;
}

int memory::allocate_mem_nf(int process_id, int num_units){
    int ct=num_units; //counting free blocks in a row
    for(int start=0;start<=MAX_SIZE-num_units;start++) {
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
    return -1;
}

int memory::allocate_mem_bf(int process_id, int num_units){
    int ct=num_units; //counting free blocks in a row
    for(int start=0;start<=MAX_SIZE-num_units;start++) {
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
    return -1;
}

int memory::allocate_mem_wf(int process_id, int num_units){
    int ct=num_units; //counting free blocks in a row
    for(int start=0;start<=MAX_SIZE-num_units;start++) {
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
    return -1;
}

void memory::allocate_mem(int mode){

    int temp;
    int del=1;
for (int i=0;i<TEST_SIZE;i++)
{
    temp = psize[i];
    if(mode==1) {
        while (allocate_mem_ff(i + 1, temp) == -1) {
            if (deallocate_mem(del) == 1) {
                del++;
            }
        }
    } else if(mode==2) {
        while (allocate_mem_bf(i + 1, temp) == -1) {
            if (deallocate_mem(del) == 1) {
                del++;
            }
        }
    } else if(mode==3) {
        while (allocate_mem_nf(i + 1, temp) == -1) {
            if (deallocate_mem(del) == 1) {
                del++;
            }
        }
    } else {
        while (allocate_mem_wf(i + 1, temp) == -1) {
            if (deallocate_mem(del) == 1) {
                del++;
            }
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
        if(i%8==0){
            cout<<endl;
        }
        cout<<allocation[i]<<" ";


    }
    cout<<"There is "<<fragment_count()<<" fragments in memory."<<endl;
}

int memory::fragment_count() {
    int check;
    fragments=0;
    check=0;
    for(int i=0;i<MAX_SIZE;i++){
        if(allocation[i] == 0 ){
            ++check;
        }
        else if(check<3 && check>0){
            fragments++;
            check=0;
        }
        else{
            check=0;
        }
    }
    return fragments;
}