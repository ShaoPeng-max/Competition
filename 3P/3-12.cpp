#include <stdio.h>
#include <string.h>

#define M  55
#define N 1005

int count(char a[], char b[], int n)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += a[i] != b[i] ? 1 : 0;
    }

    return ret;
}

void solve()
{
    int m, n;
    char dna[M][N];
    int ans = 0;
    int ham[N][4];
    char ret[N];

    memset(dna, 0, sizeof(dna));
    memset(ret, 0, sizeof(ret));
    memset(ham, 0, sizeof(ham));

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", dna[i]);
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            switch (dna[j][i])
            {
            case 'A':
                ham[i][0]++;
                break;
            case 'C':
                ham[i][1]++;
                break;
            case 'G':
                ham[i][2]++;
                break;
            case 'T':
                ham[i][3]++;
                break;
            default:
                break;
            }
            
        }
        int res = ham[i][0];
        for (int k = 0; k < 4; k++)
        {
            if (ham[i][k] > res) res = ham[i][k];
        }
        ans += (m - res);
        if (ham[i][0] == res) ret[i] = 'A';
        else if (ham[i][1] == res) ret[i] = 'C';
        else if (ham[i][2] == res) ret[i] = 'G';
        else ret[i] = 'T';
    }
    


    printf("%s\n%d\n", ret, ans);

}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
        //if (t) printf("\n");
    }
    return 0;
}