#include <stdio.h>
#include <string.h>

#define maxn 10


int a[maxn][maxn];

int main()
{
    memset(a, 0, sizeof(a));
    int n;
    scanf("%d", &n);
    int tot = 1, x, y;
    a[x=0][y=n-1] = tot;
    while (tot < n * n)
    {
        while (x + 1 < n && !a[x+1][y]) a[++x][y] = ++tot;
        while (y - 1 > -1 && !a[x][y-1]) a[x][--y] = ++tot;
        while (x - 1 > -1 && !a[x-1][y]) a[--x][y] = ++tot;
        while (y + 1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%-3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
