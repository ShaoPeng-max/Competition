#include <stdio.h>
#include <string.h>
#define maxn 100005

int a[maxn];

int main()
{
    memset(a, 0, sizeof a);
    for (int i = 1; i <= 100000; i++)
    {
        int res = i;
        int ret = i;
        while (ret > 0)
        {
            res += ret % 10;
            ret /= 10;
        }
        if (res <= 100000 && a[res] == 0 || i < a[res]) a[res] = i;
    }

    int n, c;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &c);
        printf("%d\n", a[c]);
    }

    return 0;
}
