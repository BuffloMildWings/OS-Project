#include<iostream>
#include"memory.h"


using namespace std;

int main(){
    memory process;
    process.print_mem();
    process.allocate_mem(2);
    process.print_mem();




}
