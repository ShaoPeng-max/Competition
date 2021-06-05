#include <cstdio>

const int maxn = 100005;
int left[maxn], right[maxn];

void link(int l, int r){
    right[l] = r;
    left[r] = l;
}

int main(){
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) == 2){
        for(int i = 1; i <= n; i++){
            left[i] = i - 1;
            right[i] = (i + 1) % (n + 1);
        }
        left[0] = n; right[0] = 1;
        int op, x, y, inv = 0;
        while(m--){
            scanf("%d", &op);
            if(op == 4) inv = !inv;
            else{
                scanf("%d%d", &x, &y);
            }
        }
    }
}