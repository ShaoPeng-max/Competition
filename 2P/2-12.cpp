#include <stdio.h>

int main()
{
    double i;
    for (i = 0; i != 10; i += 0.1)
    {
        printf("%.1f\n", i);
        if (i > 12.0) break;
    }
    printf("%d\n", 10 == 10.0);
    return 0;
}
