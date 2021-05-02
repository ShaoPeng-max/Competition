#include <stdio.h>
#include <string.h>
#define maxn 10005

int a[maxn][10];

int main()
{
    memset(a, 0, sizeof a);
    a[1][1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        memcpy(a[i], a[i-1], sizeof a[i]);
        int j = i;
        while (j > 0)
        {
            a[i][j%10]++;
            j /= 10;
        }
    }
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int num;
        scanf("%d", &num);
        bool ok = true;
        for (int i = 0; i < 10; i++)
        {
            if (ok) {printf("%d", a[num][i]); ok = false;}
            else printf(" %d", a[num][i]);
        }
        printf("\n");
    }


    return 0;
}
