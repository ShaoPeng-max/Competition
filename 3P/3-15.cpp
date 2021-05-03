#include <stdio.h>

bool eq(int a[2], int b[2])
{
    return (a[0] == b[0] && a[1] == b[1]);
}
void remake(int a[2])
{
    if (a[0] > a[1])
    {
        int t = a[0];
        a[0] = a[1];
        a[1] = t;
    }
}

int main()
{
    int vo[6][2];
    while (scanf("%d%d", &vo[0][0], &vo[0][1]) == 2)
    {
        bool ok = true;
        remake(vo[0]);
        for (int i = 1; i < 6; i++)
        {
            scanf("%d%d", &vo[i][0], &vo[i][1]);
            remake(vo[i]);
        }

        int vis[6] = {0, 0, 0, 0, 0, 0};
        int vcl[3][2], k = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                if (!vis[i] && !vis[j] && eq(vo[i], vo[j]))
                {
                    vis[i] = 1;
                    vis[j] = 1;
                    vcl[k][0] = vo[i][0];
                    vcl[k][1] = vo[i][1];
                    k++;
                }
            }
        }
        for (int i = 0; i < 6; i++)
        {
            if (!vis[i])
            {
                ok = false;
                break;
            }
            
        }
        
        int a1 = vcl[0][0], a2 = vcl[0][1];
        int b1 = vcl[1][0], b2 = vcl[1][1];
        int c1 = vcl[2][0], c2 = vcl[2][1];
        bool a = (a1 == b1 && a2 == c1 && b2 == c2);
        bool b = (a1 == b1 && a2 == c2 && b2 == c1);
        bool c = (a1 == b2 && a2 == c1 && b1 == c2);
        bool d = (a1 == b2 && a2 == c2 && b1 == c1);
        bool e = (a1 == c1 && a2 == b1 && b2 == c2);
        bool h = (a1 == c2 && a2 == b1 && b2 == c1);
        bool f = (a1 == c1 && a2 == b2 && b1 == c2);
        bool g = (a1 == c2 && a2 == b2 && b1 == c1);
        bool is = ok & (a | b | c | d | e | f | g | h);
        printf("%s\n", is ? "POSSIBLE" : "IMPOSSIBLE");
    }
}