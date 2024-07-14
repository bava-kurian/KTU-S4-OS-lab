
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
    shmid = shmget((ket_t)1222, 1024, 0666 | IPC CREAT);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("process attached at %p\n", shared_memory);
    printf("Enter some data to write\n");
    read(0, buffer, 100);
    strcpy(shared_memory, buffer);
    printf("You wrote is : %s\n", shared_memory);
    return 0;
}
