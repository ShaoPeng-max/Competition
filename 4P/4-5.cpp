#include <stdio.h>
#include <string.h>

#define n 15
#define v 1

int isv[n][n];
int pos[n][n];
int gbx, gby;

int islegal(int x, int y){
    if (x >= 1 && x <= 10 && y >= 1 && y <= 9) return 1;
    return 0;
}

int isin(int x, int y){
    if (x >= 1 && x <= 3 && y >= 4 && y <= 6) return 1;
    return 0;
}

void valify(int x, int y){
    if (pos[x][y] == 'G'){
        for (int i = x - 1; i >= 1; i--){
            isv[i][y] = v;
            if (pos[i][y] != 0) break;
        }
    }
    if (pos[x][y] == 'R'){
        int i, j;
        for (int i = x + 1, j = y; islegal(i, j); i++){
            isv[i][j] = v;
            if (pos[i][j] != 0) break;
        }
        for (int i = x - 1, j = y; islegal(i, j); i--){
            isv[i][j] = v;
            if (pos[i][j] != 0) break;
        }
        for (int i = x, j = y - 1; islegal(i, j); j--){
            isv[i][j] = v;
            if (pos[i][j] != 0) break;
        }
        for (int i = x, j = y + 1; islegal(i, j); j++){
            isv[i][j] = v;
            if (pos[i][j] != 0) break;
        }
    }
    if (pos[x][y] == 'C'){
        int i, j, p;
        for (i = x + 1, j = y, p = 0; islegal(i, j); i++){
            if (p) isv[i][j] = v;
            if (pos[i][j] != 0){
                if (!p) p = 1; else break;
            }
        }
        for (i = x - 1, j = y, p = 0; islegal(i, j); i--){
            if (p) isv[i][j] = v;
            if (pos[i][j] != 0){
                if (!p) p = 1; else break;
            }
        }
        for (i = x, j = y - 1, p = 0; islegal(i, j); j--){
            if (p) isv[i][j] = v;
            if (pos[i][j] != 0){
                if (!p) p = 1; else break;
            }
        }
        for (i = x, j = y + 1, p = 0; islegal(i, j); j++){
            if (p) isv[i][j] = v;
            if (pos[i][j] != 0){
                if (!p) p = 1; else break;
            }
        }
    }
    if (pos[x][y] == 'H'){
        if (islegal(x+2, y+1) && !pos[x+1][y]) isv[x+2][y+1] = v;
        if (islegal(x+2, y-1) && !pos[x+1][y]) isv[x+2][y-1] = v;
        if (islegal(x-2, y+1) && !pos[x-1][y]) isv[x-2][y+1] = v;
        if (islegal(x-2, y-1) && !pos[x-1][y]) isv[x-2][y-1] = v;
        if (islegal(x+1, y+2) && !pos[x][y+1]) isv[x+1][y+2] = v;
        if (islegal(x-1, y+2) && !pos[x][y+1]) isv[x-1][y+2] = v;
        if (islegal(x+1, y-2) && !pos[x][y-1]) isv[x+1][y-2] = v;
        if (islegal(x-1, y-2) && !pos[x][y-1]) isv[x-1][y-2] = v;
    }
}

void display(){
    for (int i = 1; i < 11; i++){
        for (int j = 1; j < 10; j++){
            printf("%3d ", isv[i][j]);
        }
        printf("\n\n");
    }
}

int main(){
    int cnt;
    int X[10], Y[10];
    char S[10];
    while(scanf("%d%d%d", &cnt, &gbx, &gby) == 3 && cnt){
        memset(pos, 0, sizeof(pos));
        memset(isv, 0, sizeof(isv));
        
        for (int i = 0; i < cnt; i++){
            scanf(" %c %d %d", &S[i], &X[i], &Y[i]);
            pos[X[i]][Y[i]] = (int)S[i];
        }
        for (int i = 0; i < cnt; i++){
            valify(X[i], Y[i]);
        }
        int x = gbx, y = gby;
        //display();
        if(!isv[x][y]) printf("NO\n");
        else if(isin(x+1, y) && isv[x+1][y] == 0) printf("NO\n");
        else if(isin(x-1, y) && isv[x-1][y] == 0) printf("NO\n");
        else if(isin(x, y+1) && isv[x][y+1] == 0) printf("NO\n");
        else if(isin(x, y-1) && isv[x][y-1] == 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}