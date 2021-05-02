#include <stdio.h>

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        bool ok = false;
        int cnt = 1;
        for (int p = 10; p < 101; p++)
        {
            if (p % 3 == a && p % 5 == b && p % 7 == c)
            {
                ok = true;
                printf("Case %d: %d\n", cnt, p);
            }
        }
        if (!ok)
        {
            printf("Case %d: No answer\n", cnt);
        }
        cnt++;
    }
}
