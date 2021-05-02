#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int res = 100*i + 10*j + k;
                if (pow(i, 3) + pow(j, 3) + pow(k, 3) == res)
                    printf("%d\n", res);
            }
        }
    }

}
