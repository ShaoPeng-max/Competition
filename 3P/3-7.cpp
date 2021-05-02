#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define maxn 90

char s[maxn];
char f[4] = {'C', 'H', 'O', 'N'};
double m[4] = {12.01, 1.008, 16.00, 14.01};


double solve(char* s)
{
    double ret = 0;
    int num[4] = {0, 0, 0, 0};
    int i = 0;
    int n = strlen(s);
    while (i < n)
    {
        if (isalpha(s[i]))
        {
            char res[maxn] = {};
            int j = i + 1;
            while (j < n && isdigit(s[j]))
            {
                res[j-i-1] = s[j];
                j += 1;
            }

            for (int k = 0; k < 4; k++)
            {
                if (s[i] == f[i])
                {
                    num[i] += strlen(res) == 0 ? 1 : atoi(res);
                }
            }
            i = j;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        ret += num[i] * m[i];
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        printf("%.3f\n", solve(s));
    }

    return 0;
}
