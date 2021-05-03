#include <stdio.h>
#include <string.h>

#define n 1000000

int main()
{
    char a[n], b[n];
    while (scanf("%s%s", a, b) == 2)
    {
        int i = 0, j = 0;
        while (i < strlen(a) && j < strlen(b))
        {
            if (a[i] == b[j])
            {
                i++; j++;
            }
            else j++;
        }
        printf("%s\n", i == strlen(a) ? "Yes":"No");
    }
}