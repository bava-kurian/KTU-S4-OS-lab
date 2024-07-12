#include <stdio.h>
void main()
{
    int pg[100], fr[100], i, j, k = 0, m, n, found, count[100], flag[100], pf = 0, next = 1, min;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the  umber of frames: ");
    scanf("%d", &m);
    printf("Enter the pages: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pg[i]);
        flag[i] = 0;
    }
    for (j = 0; j < m; j++)
    {
        fr[j] = -1;
        count[j] = 0;
    }
    printf("The page replacement process is: \n");
    printf("\nReference string | Page Frames | Status | \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (fr[j] == pg[i])
            {
                flag[i] = 1;
                count[j] = next;
                next++;
                break;
            }
        }
        if (flag[i] == 0)
        {
            min = 0;
            for (j = 1; j < m; j++)
            {
                if (count[min] > count[j])
                {
                    min = j;
                }
            }
            fr[min] = pg[i];
            count[min] = next;
            next++;
            pf++;
        }

        for (j = 0; j < m; j++)
        {
            if (fr[j] != -1)
            {
                printf("%2d", fr[j]);
            }
            else
            {
                printf("-");
            }
        }
        if (flag[i] == 0)
        {
            printf("   |  MISS\n");
        }
        else
        {
            printf("   |  HIT\n");
        }
    }

    printf("Total page faults: %d", pf);
}