#include <stdio.h>
#include <string.h>
#define maxn 1000 + 5

int lights[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(lights, 0, sizeof lights);
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; i <= n; j += i)
        {
            lights[j] = !lights[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (lights[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
