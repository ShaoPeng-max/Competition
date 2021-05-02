#include <stdio.h>
#include <string.h>
#define maxn 90

char s[maxn];

void solve(char* s)
{
    int o = 0, x = 0;
    int ret = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'O')
        {
            o++;
            ret += o;
        }
        else
        {
            o = 0;
        }
    }
    printf("%d\n", ret);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        solve(s);
    }

    return 0;
}
