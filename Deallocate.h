//
// Created by latun on 11/13/2017.
//

#define MAX_SIZE 128

/*
 * Deallocate only works on arrays
 * Takes an integer
 * Returns 1 or -1
 */
int deallocate(int process_id){
    int mem_location[MAX_SIZE]; //Needs to be removed later
    int i=0;
    bool rem_flag=false;
    //initialize mem_location for testing
    for (i;i<MAX_SIZE;i++) {
        mem_location[i]=0;
    }
    i=0;
    while(i<MAX_SIZE){
           if(rem_flag ||mem_location[i]==process_id){
               rem_flag=true;
               mem_location[i]=0;
               if(mem_location[i+1]!=process_id){
                   return 1;
               }

           }
        i++;
    }
    return -1;

}





