#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
//    int n;
//    scanf("%d", &n);
//    if (n <= 1)
//    {
//        printf("wrong input");
//        return 0;
//    }
//    int ret = 0;
//    while (n > 1)
//    {
//        if (n & 1)
//        {
//            n = 3 * n + 1;
//            printf("%d -> %d\n", (n - 1) / 3, n);
//        }
//        else
//        {
//            printf("%d - >", n);
//            n /= 2;
//            printf("%d\n", n);
//        }
//        ret++;
//    }
//    printf("%d\n", ret);
    int n, cnt = 0;
    scanf("%d", &n);
    long long m = n;
    cout << "m = " << m << " n = " << n << endl;
    while (m > 1)
    {
        if (m & 1) m = m * 3 + 1;
        else m /= 2;
        cnt++;
    }
    cout << cnt << endl;
    printf("%d\n", cnt);
    return 0;

}
