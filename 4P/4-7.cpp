#include <stdio.h>
#include <string.h>
#define n 10

char b[n][n];
int a[n][n];
int t[n][n];

int islegal(int i, int j){
    if (i >= 0 && i <= 7 && j >= 0 && j <= 7) return 1;
    return 0;
}

void cnt(int x, int y, char type){
    char o = type == 'W' ? 'B' : 'W';
    int i, j;
    for (i = x - 1, j = y; islegal(i, j); i--){
        if (b[i][j] != o){
            if (x - i > 1)
                a[i][j] = 1;
            break;
        }
    }
    for (i = x + 1, j = y; islegal(i, j); i++){
        if (b[i][j] != o){
            if (i - x > 1)
                a[i][j] = 1;
            break;
        }
    }
    for (i = x, j = y - 1; islegal(i, j); j--){
        if (b[i][j] != o){
            if (y - j > 1)
                a[i][j] = 1;
            break;
        }
    }
    for (i = x, y = y + 1; islegal(i, j); j++){
        if (b[i][j] != o){
            if (y - j > 1)
                a[i][j] = 1;
            break;
        }
    }

}

void make(int x, int y, char type){
    char o = type == 'W' ? 'B' : 'W';
    int i, j;
    for (i = x - 1, j = y; islegal(i, j); i--){
        if (b[i][j] != o){
            if (x - i > 1 && b[i][j] == type){
                for (int k = x - 1; k > i; k--){
                    t[k][j] = 1;
                }
            }
            break;
        }
    }
    for (i = x + 1, j = y; islegal(i, j); i++){
        if (b[i][j] != o){
            if (i - x > 1 && b[i][j] == type){
                for (int k = x + 1; k < i; k++){
                    t[k][j] = 1;
                }
            }
            break;
        }
    }
    for (i = x, j = y - 1; islegal(i, j); j--){
        if (b[i][j] != o){
            if (y - j > 1 && b[i][j] == type){
                for (int k = y - 1; k > j; k--){
                    t[i][k] = 1;
                }
            }
            break;
        }
    }
    for (i = x, y = y + 1; islegal(i, j); j++){
        if (b[i][j] != o){
            if (y - j > 1 && b[i][j] == type){
                for (int k = y + 1; k < j; k++){
                    t[i][k] = 1;
                }
            }
            break;
        }
    }
    for (i = 0; i < 64; i++){
        if (t[i / 8][i % 8]) b[i / 8][i % 8] = type;
    }
}

void show_legal(){
    bool ok = false;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (a[i][j]){
                if (ok) putchar(' ');
                printf("(%d,%d)", i+1, j+1);
                ok = true;
            }
        }
    }
    if (ok) putchar('\n');
    else printf("No legal move.\n");
}

int main(){
    int g;
    while (scanf("%d", &g) == 1 && g){
        while (g){
            for(int i = 0; i < 8; i++)
                scanf("%s", b[i]);
            char p;
            char c[5];
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            memset(t, 0, sizeof(t));
            while (scanf("%s", c)){
                if (c[0] == '\n') continue;
                if (c[0] == 'W' || c[0] == 'B'){
                    p = c[0];
                    continue;
                } 
                if (c[0] == 'L'){
                    
                    for (int i = 0; i < 8; i++){
                        for (int j = 0; j < 8; j++){
                            if (b[i][j] == p) cnt(i, j, p);
                        }
                    }
                    show_legal();
                }
                if (c[0] == 'M'){
                    bool p2 = true;
                    for (int i = 0; i < 8; i++){
                        for (int j = 0; j < 8; j++){
                            if (b[i][j] == p) cnt(i, j, p);
                        }
                    }
                    for (int i = 0; i < 64; i++){
                        if (a[i / 8][i % 8]) {p2 = false; break;}
                    }
                    int x = c[1] - '0', y = c[2] - '0';
                    if (p2) p = p == 'W' ? 'B' : 'W';
                    make(x, y, p);
                    int f1 = 0, f2 = 0;
                    for (int i = 0; i < 64; i++){
                        if (b[i / 8][i % 8] == 'W') f1++;
                        if (b[i / 8][i % 8] == 'B') f2++;
                    }
                    printf("Black - %d White - %d\n", f1, f2);
                }
                if (c[0] == 'Q'){
                    g--;
                    for (int i = 0; i < 8; i++){
                        printf("%s\n", b[i]);
                    }
                    putchar('\n');
                }
            }

        }
    }
}