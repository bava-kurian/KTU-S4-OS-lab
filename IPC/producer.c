#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    void *shared_memory;
    int shmid;
    char buffer[100];
    shmid = shmget((ket_t)1222, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("process attached at %p\n", shared_memory);
    printf("Data read : %s\n", (char *)shared_memory);
    return 0;
}