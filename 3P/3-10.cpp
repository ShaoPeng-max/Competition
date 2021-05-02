#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxn 10
#define SIZE 5


void show(int k, char s[SIZE][SIZE])
{
    printf("Puzzle #%d:\n", k);
    for (int i = 0; i < SIZE; i++)
    {
        putchar(s[i][0]);
        for (int j = 1; j < SIZE; j++)
        {
            printf(" %c", s[i][j]);
        }
        printf("\n");
        
    }
}

bool change(char c, int* x, int* y, char s[SIZE][SIZE])
{
    if (c == 'A')
    {
        if (*x <= 0) return false;
        else {s[*x][*y] = s[*x-1][*y]; s[--(*x)][*y] = ' ';}
    }
    else if (c == 'B')
    {
        if (*x >= 4) return false;
        else {s[*x][*y] = s[*x+1][*y]; s[++(*x)][*y] = ' ';}
    }
    else if (c == 'L')
    {
        if (*y <= 0) return false;
        else {s[*x][*y] = s[*x][*y-1]; s[*x][--(*y)] = ' ';}
    }
    else if (c == 'R')
    {
        if (*y >= 4) return false;
        else {s[*x][*y] = s[*x][*y+1]; s[*x][++(*y)] = ' ';}
    }
    return true;
}

void solve()
{
    bool ok = true;
    char c;
    int k = 0;
    
    while (ok)
    {
        char s[SIZE][SIZE];
        int x, y;
        bool isprint = true;
        int i = 0;
        while (i < SIZE * SIZE)
        {
            char ch;
            while ((ch = getchar()) != '\n')
            {
                if (ch == 'Z')
                {
                    ok = false;
                    break;
                }
                if (ch == ' ')
                {
                    x = i / SIZE, y = i % SIZE;
                }
                s[i / SIZE][i % SIZE] = ch;
                i++;
            }
            if (!ok) break;          
        }
        if (!ok) break;
        while ((c = getchar()) != '0')
        {
            if (isupper(c))
            {
                if (!change(c, &x, &y, s))
                {
                    printf("Puzzle #%d:\n", ++k);
                    puts("This puzzle has no final configuration.");
                    isprint = false;
                    break;
                }
            }
            else continue;
        }
        getchar();
        if (isprint) show(++k, s);
    }
    

}



int main()
{
    solve();

    return 0;
}
