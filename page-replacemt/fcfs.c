#include <stdio.h>
void main()
{
    int pg[100], fr[100], i, j, k = 0, m, n, found, count = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the  umber of frames: ");
    scanf("%d", &m);
    printf("Enter the pages: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pg[i]);
    }
    for (j = 0; j < m; j++)
    {
        fr[j] = -1;
    }
    printf("\n Reference string | Page Frames | Status | \n");
    for (i = 0; i < n; i++)
    {
        found = 0;
        printf("%10d        |", pg[i]);
        for (j = 0; j < m; j++)
        {
            if (pg[i] == fr[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            fr[k] = pg[i];
            k = (k + 1) % m;
            count++;
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
        if (found)
        {
            printf("   |  HIT\n");
        }
        else
        {
            printf("   |  MISS\n");
        }
    }
    printf("Total page faults: %d\n", count);
}