#include <stdio.h>
#include <string.h>
#define n 10

int H[n][n];
int V[n][n];
int ret[n];
int v, m;

void cnt(int x, int y){
    int res = 0;
    int len = x < y ? v - y : v - x;
    int x1, y1, x2, y2;
    for (int l = 1; l <= len; l++){
        bool ok = true;
        for (x1 = x, y1 = y, x2 = x + l, y2 = y; y1 < y + l && y2 < y + l; y1++, y2++){
            if (H[x1][y1] == 0 || H[x2][y2] == 0){
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        for (x1 = x, y1 = y, x2 = x, y2 = y + l; x1 < x + l && x2 < x + l; x1++, x2++){
            if (V[x1][y1] == 0 || V[x2][y2] == 0){
                ok = false;
                break;
            }
        }
        if (ok) ret[l]++;
    }
}

int main(){
    int kase = 0;
    while (scanf("%d%d", &v, &m) == 2){
        memset(ret, 0, sizeof(ret));
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        char type;
        int x, y;
        for (int i = 0; i < m; i++){
            scanf(" %c %d %d", &type, &x, &y);
            type == 'H' ? H[x][y] = 1 : V[y][x] = 1;
        }
        int has = 0;
        for (int i = 1; i < v; i++){
            for (int j = 1; j < v; j++){
                cnt(i, j);
            }
        }
        if (kase){
            printf("\n**********************************\n\n");
        }
        printf("Problem #%d\n\n", ++kase);
        for (int i = 1; i < v; i++)
        {
            if (ret[i] > 0){
                printf("%d square (s) of size %d\n", ret[i], i);
                has = 1;
            }
        }
        if (!has) printf("No completed squares can be found.\n");
    }
    return 0;
}