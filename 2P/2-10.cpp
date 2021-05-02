#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3)
    {
        if (a == 0 && b == 0 && c== 0) break;
        printf("%d.", a / b);
        for (int i = 1; i < c; i++)
        {
            a *= 10;
            printf("%d", (a / b) % 10);
            a %= b;
        }
        int s = floor(10.0 * a / b + 0.5);
        printf("%d\n", s);

    }

    return 0;
}
