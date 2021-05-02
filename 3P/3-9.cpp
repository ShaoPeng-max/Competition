#include <stdio.h>
#include <string.h>

#define maxn 100

char s[maxn];


int solve()
{
    scanf("%s", s);
    for (int p = 1; p < strlen(s); p++)
    {
        bool ok = true;
        if (strlen(s) % p) continue;
        for (int i = 0; i < p; i++)
        {
            char f = s[i];

            for (int j = i + p; j < strlen(s); j+=p)
            {
                ok &= f == s[j];
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (!ok) continue;
        else return p;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        printf("%d\n", solve());
        if (n) printf("\n");
    }
}
