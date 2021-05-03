#include <bits/stdc++.h>
#define N 500

using namespace std;

int main()
{
    char l1[N], l2[N];
    int res[N];
    while (scanf("%s%s", l1, l2) == 2)
    {
        memset(res, 0, sizeof(res));
        int n1 = strlen(l1), n2 = strlen(l2);
        for (int i = n1; i < n1 + n2; i++)
            res[i] = l2[i-n1] - '0';
        int ret = n1 + n2;
        for (int i = 0; i < n1 + n2; i++)
        {
            int len = max(i + n1, n1 + n2) - min(i, n1);
            bool ok = true;
            for (int j = 0; j < n1; j++)
            {
                if (res[i+j] + (l1[j] - '0') > 3) ok = false;
            }
            if (ok) ret = min(ret, len);
        }
        printf("%d\n", ret);
    }

    return 0;
}