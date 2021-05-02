#include <stdio.h>
#include <string.h>

#define n 15

void solve()
{
    int r, c;
    int kase = 1;
    while (scanf("%d", &r) == 1 && r)
    {
        scanf("%d", &c);
        if (kase > 1)
        {
            printf("\n");
        }
        char grid[n][n];
        int init[n][n];
        int res[n][n];
        char s[r * c + 1][r+1];
        memset(s, 0, sizeof(s));
        memset(init, 0, sizeof(init));
        memset(res, 0, sizeof(res));
        int cnt = 1;

        for (int i = 0; i < r; i++)
        {
            scanf("%s", grid[i]);
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] != '*')
                {
                    if (i == 0 || grid[i-1][j] == '*' || j == 0 || grid[i][j-1] == '*')
                    {
                        init[i][j] = cnt++;
                    }
                }
                    
            }
        }

        printf("puzzle #%d:\nAcross", kase++);
        for (int i = 0; i < r; i++)
        {
            bool f = true;          
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '*')
                {
                    f = true;
                }
                else
                {
                    if (f) 
                    {
                        f = false; 
                        printf("\n%3d.%c", init[i][j], grid[i][j]);
                    }
                    else
                    {
                        printf("%c", (grid[i][j]));
                    }
                        
                }
            }
        }
        printf("\nDown\n");
        
        for (int j = 0; j < c; j++)
        {
            bool f = true;
            int k = 0;
            int to = 1;
            for (int i = 0; i < r; i++)
            {
                if (grid[i][j] == '*') 
                {
                    f = true;
                }
                else
                {
                    char cur = grid[i][j];
                    if (f) 
                    {
                        k = init[i][j]; 
                        to = 0; 
                        f = false; 
                        s[k][to++] = cur;
                    }
                    else
                    {
                        s[k][to++] = cur;
                    } 
                        
                }
            }
        }
        for (int i = 1; i <= r * c; i++)
        {
            if (strlen(s[i]))
            {
                printf("%3d.%s\n", i, s[i]);
            }
        }
    }
    
}

int main()
{
    solve();
    return 0;
}