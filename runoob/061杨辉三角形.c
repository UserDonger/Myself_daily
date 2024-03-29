#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(int argc, char *argv[])
{
    int i, j;
    int a[MAX][MAX] = {};
    for (i = 0; i < MAX; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for (i = 2; i < MAX; i++)
    {
        for (j = 1; j < i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%-4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
