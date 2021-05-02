// chicken and rabbit
#include <stdio.h>

int main()
{
    int chicken, rabbit, m, n;
    scanf("%d%d", &m, &n);

    rabbit = (n - 2*m) / 2;
    chicken = m - rabbit;

    if (m & 1 || chicken < 0 || rabbit < 0)
        printf("No answer\n");
    else
        printf("%d %d\n", chicken, rabbit);

    return 0;
}