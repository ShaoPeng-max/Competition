#include <stdio.h>

int main()
{
    int n, m;


    while (scanf("%d%d", &n, &m) == 2 && n && m)
    {
        double ans = 0.0;
        for (int i = n; i <= m; i++)
        {
            long long res = (long long)i * i;
            ans += 1.0 / res;
        }

        printf("%.6f\n", ans);
    }


    return 0;
}
