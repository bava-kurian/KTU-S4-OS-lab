#include <stdio.h>
int First(int b[10], int bno)
{
    int process, i, p, flag = 0;
    printf("Enter the processes :");
    scanf("%d", &process);
    for (i = 0; i < process; i++)
    {
        if (b[i] >= process)
        {
            b[i] = b[i] - process;
            p = i;
            printf("Process allocated \n");
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    if (flag == 1)
    {
        printf("Not allocated\n");
    }
printf("------------------------------------------
\n");
printf("|");
for(i=0; i<bno; i++)
{
        if (i == p)
        {
            printf(" //%d// |", b[p]);
        }
        else
            printf(" %d |", b[i]);
}
printf("\n----------------------------------------
\n");
}
int Best(int b[10], int bno)
{
    int process, i, j, temp, p, flag, t[10];
    printf("Enter the processes :");
    scanf("%d", &process);
    for (i = 0; i < bno; i++)
    {
        t[i] = b[i];
    }
    for (i = 0; i < bno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (t[i] < t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    for (i = 0; i < bno; i++)
    {
        if (process <= t[i])
        {
            for (j = 0; j < bno; j++)
            {
                if (b[j] == t[i])
                {
                    b[j] = b[j] - process;
                    p = j;
                }
            }
            printf("Process allocated \n");
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    if (flag == 1)
    {
        printf("Not allocated\n");
    }
printf("\n------------------------------------------
\n");
printf("|");
for(i=0; i<bno; i++)
{
        if (i == p)
        {
            printf(" //%d// |", b[p]);
        }
        else
        {
            printf(" %d |", b[i]);
        }
}
printf("\n------------------------------------------
\n");
}
int Worst(int b[10], int bno)
{
    int process, i, j, temp, p, flag, t[10];
    printf("Enter the processes :");
    scanf("%d", &process);
    for (i = 0; i < bno; i++)
    {
        t[i] = b[i];
    }
    for (i = 0; i < bno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (t[i] > t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
    for (i = 0; i < bno; i++)
    {
        if (process <= t[i])
        {
            for (j = 0; j < bno; j++)
            {
                if (b[j] == t[i])
                {
                    b[j] = b[j] - process;
                    p = j;
                }
            }
            printf("Process allocated\n");
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    if (flag == 1)
        printf("Not allocated\n");
printf("\n---------------------------------------
\n");
printf("|");
for(i=0; i<bno; i++)
{
        if (i == p)
        {
            printf(" //%d// |", b[p]);
        }
        else
            printf(" %d |", b[i]);
}
printf("\n----------------------------------------
\n");
}
void main()
{
    int b[10], bno, process, i, j, c;
    printf("Enter the size of blocks : ");
    scanf("%d", &bno);
    printf("Enter the memory blocks :\n");
    for (i = 0; i < bno; i++)
    {
        scanf("%d", &b[i]);
    }
    do
    {
printf("\n1.First fit\n2.Best 
fit\n3.Worstfit\n4.Exit\n");
printf("Enter choice :\n");
scanf("%d",&c);
switch(c)
{
        case 1:
            First(b, bno);
            break;
        case 2:
            Best(b, bno);
            break;
        case 3:
            Worst(b, bno);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
}
    } while (c != 4);
}