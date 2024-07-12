
#include <stdio.h>
struct frame
{
    int content;
    int frequency;
    int count;
};
void main()
{
    int i, j, pg[20], pf = 0, n, m, hit, k = 0, min;
    struct frame fr[20];
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &m);
    printf("Enter the pages: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pg[i]);
    }
    for (j = 0; j < m; j++)
    {
        fr[j].content = -1;
        fr[j].frequency = 0;
        fr[j].count = 0;
    }
    printf("The page replacement process is: \n");
    for (i = 0; i < n; i++)
    {
        hit = 0;
        for (j = 0; j < m; j++)
        {
            if (pg[i] == fr[j].content)
            {
                fr[j].frequency++;
                fr[j].count++;
                hit = 1;
                break;
            }
        }
        if (!hit)
        {
            if (k < m) // space is available in it
            {
                fr[k].content = pg[i];
                fr[k].frequency = 1;
                fr[k].count = i;
                k++;
                pf++;
            }
            else
            {
                min = 0;
                for (j = 0; j < m; j++)
                {
                    if (fr[min].frequency > fr[j].frequency)
                    {
                        min = j;
                    }
                    else if (fr[min].frequency == fr[j].frequency && fr[min].count > fr[j].count)
                    {
                        min = j;
                    }
                }
                fr[min].content = pg[i];
                fr[min].frequency = 1;
                fr[min].count = i;
                pf++;
            }
        }
        for (j = 0; j < m; j++)
        {
            if (fr[j].content != -1)
            {
                printf("%2d", fr[j].content);
            }
            else
            {
                printf("-");
            }
        }
        if (hit)
        {
            printf("   |  HIT\n");
        }
        else
        {
            printf("   |  MISS\n");
        }
    }
}
