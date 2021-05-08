#include <stdio.h>
#include <string.h>
#define maxd 10000

struct Commnand
{
    char c[5];
    int r1, c1, r2, c2;
    int x;
    int a[20];
} cmd[maxd];

int r, c, n;

int simulate(int *r, int *c)
{
    for (int i = 0; i < n; i++)
    {
        if (cmd[i].c[0] == 'E')
        {
            if (cmd[i].r1 == *r && cmd[i].c1 == *c)
            {
                *r = cmd[i].r2, *c = cmd[i].c2;
            }
            else if (cmd[i].r2 == *r && cmd[i].c2 == *c)
            {
                *r = cmd[i].r1, *c = cmd[i].c1;
            }
        }
        int dr = 0, dc = 0;
        for (int j = 0; j < cmd[i].x; j++)
        {
            if (!strcmp(cmd[i].c, "IR"))
            {
                if (cmd[i].a[j] <= *r)
                    dr++;
            }
            else if (!strcmp(cmd[i].c, "IC"))
            {
                if (cmd[i].a[j] <= *c)
                    dc++;
            }
            else if (!strcmp(cmd[i].c, "DR"))
            {
                if (cmd[i].a[j] == *r)
                    return 0;
                if (cmd[i].a[j] < *r)
                    dr--;
            }
            else if (!strcmp(cmd[i].c, "DC"))
            {
                if (cmd[i].a[j] == *c)
                    return 0;
                if (cmd[i].a[j] < *c)
                    dc--;
            }
        }
        *r += dr;
        *c += dc;
    }
    return 1;
}

int main()
{
    int q, kase = 0;
    while (scanf("%d%d", &r, &c) == 2 && r)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", cmd[i].c);
            if (cmd[i].c[0] == 'E')
            {
                scanf("%d%d%d%d", &cmd[i].r1, &cmd[i].c1, &cmd[i].r2, &cmd[i].c2);
            }
            else
            {
                scanf("%d", &cmd[i].x);
                for (int j = 0; j < cmd[i].x; j++)
                {
                    scanf("%d", &cmd[i].a[j]);
                }
            }
        }
        if (kase)
            putchar('\n');
        printf("Spreadsheet #%d\n", ++kase);
        scanf("%d", &q);
        for (int k = 0; k < q; k++)
        {
            scanf("%d%d", &r, &c);
            printf("Cell data in (%d,%d) ", r, c);
            int ok = simulate(&r, &c);
            if (!ok)
                printf("GONE\n");
            else
                printf("moved to (%d,%d)\n", r, c);
        }
    }
    return 0;
}
