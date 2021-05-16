#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    for(;;){
        cin >> n;
        map<int, int> rec;
        if(!n) break;
        while(n--){cin >> x >> y; rec[x]--; rec[y]++;}
        bool ok = true;
        for(map<int, int>::iterator it = rec.begin(); it != rec.end(); it++){
            if(it->second != 0){
                ok = false;
                break;
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}