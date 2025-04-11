#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* routine();

int main(int argc, char* argv[]){

    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL)){
        return 1;
    }
    if(pthread_join(t1, NULL)){
        return 2;
    }

    printf("Hello from main thread...\n");

    if (pthread_create(&t2, NULL, &routine, NULL)){
        return 3;
    }
    if(pthread_join(t2, NULL)){
        return 4;
    }
    return 0;

}


void* routine(){
    printf("Hello from threads!\n");
    return 0;
}