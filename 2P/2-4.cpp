#include <stdio.h>

int main()
{
    const int c = -1;
    double sum = 0.0;
    int cur = -1;

    for (int i = 0; ; i++)
    {
        cur *= c;
        double res = cur / (2 * i + 1);
        if (res < 1e-6) break;
        sum += res;

    }

    printf("%.6f\n", sum);

    return 0;
}
