#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{

    int n, cnt = 0;
    scanf("%d", &n);
    long long m = n;
    cout << "m = " << m << " n = " << n << endl;
    while (m > 1)
    {
        if (m & 1)
            m = m * 3 + 1;
        else
            m /= 2;
        cnt++;
    }
    cout << cnt << endl;
    printf("%d\n", cnt);
    return 0;
}
