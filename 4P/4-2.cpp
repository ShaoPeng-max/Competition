#include <stdio.h>
#include <string.h>

int codes[8][1 << 8];

int readchar()
{
    for (;;)
    {
        int ch = getchar();
        if (ch != '\n' && ch != '\r')
            return ch;
    }
}

int readint(int c)
{
    int ret = 0;
    while (c--)
    {
        ret = ret * 2 + readchar() - '0';
    }
    return ret;
}

int readcodes()
{
    memset(codes, 0, sizeof(codes));
    codes[1][0] = readchar();
    for (int len = 2; len < 8; len++)
    {
        for (int i = 0; i < (1 << len) - 1; i++)
        {
            int ch = getchar();
            if (ch == EOF)
                return 0;
            if (ch == '\n' || ch == '\r')
                return 1;
            codes[len][i] = ch;
        }
    }
    return 1;
}

int main()
{
    while (readcodes())
    {
        for (;;)
        {
            int len = readint(3);
            if (len == 0)
                break;
            for (;;)
            {
                int c = readint(len);
                if (c == (1 << len) - 1)
                    break;
                putchar(codes[len][c]);
            }
        }
        putchar('\n');
    }
    return 0;
}