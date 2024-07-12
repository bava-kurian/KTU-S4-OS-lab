#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("producer produces item %d\n", x);
    mutex++;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("consumer consumes item %d\n", x);
    x--;
    mutex++;
}
int main()
{
    int i, n;
    printf("\n Press 1 for producer\n Press 2 for consumer\nPress 3 for exit\n");
    while (1)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && empty != 0)
            {
                producer();
            }
            else
            {
                printf("Buffer is full\n");
            }
            break;
        case 2:
            if ((mutex == 1) && full != 0)
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty\n");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
        }
    }
}