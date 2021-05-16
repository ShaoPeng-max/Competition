#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        int t, x, ret = 0;
        cin >> t >> x;
        queue<int> q;
        priority_queue<int> Max;
        for(int i = 0; i < t; i++){
            int v; cin >> v;
            Max.push(v);
            i == x ? v += 20000 : v += 10000;
            q.push(v);
        }
        while(true){
            int p = q.front();
            q.pop();
            if(p % 10000 < Max.top())q.push(p);
            else{
                if(p >= 20000){ret++; cout << ret << endl; break;}
                else{Max.pop(); ret++;}
            }
        }
    }
    return 0;
}