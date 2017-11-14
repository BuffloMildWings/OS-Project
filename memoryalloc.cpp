#include<iostream>
#include"memory.h"
#include "Deallocate.h"

using namespace std;

int main(){
    memory process;
    process.print_mem();
    process.allocate_mem(1);
    process.print_mem();




}
