#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* routine();

int main(int argc, char* argv[]){

    pthread_t t1;
    if (pthread_create(&t1, NULL, &routine, NULL)){
        return 1;
    }
    if(pthread_join(t1, NULL)){
        return 2;
    }
    return 0;

}


void* routine(){
    printf("Hello from threads!");
    return 0;
}