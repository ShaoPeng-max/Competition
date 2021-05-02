#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int kase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        printf("Game %d:\n", ++kase);
        int* ans = new int[n];
        int* res = new int[n];
        for (int i = 0; i < n; i ++)
        {
            scanf("%d", &ans[i]);
        }
        for(;;)
        {
            int A = 0, B = 0;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &res[i]);
                A = ans[i] == res[i] ? A + 1 : A;
            }
            if (res[0] == 0) break;
            for (int i = 1; i < 10; i++)
            {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++)
                {
                    c1 = i == ans[j] ? c1 + 1 : c1;
                    c2 = i == res[j] ? c2 + 1 : c2;
                }
                if (c1 < c2) B += c1; else B += c2;
            }
            printf("    (%d,%d)\n", A, B-A);

        }

    }
    return 0;
}
