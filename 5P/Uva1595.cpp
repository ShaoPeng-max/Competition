#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while(n--){
        vector<int> yval[20005];    
        int m; cin >> m;
        while(m--){
            int x, y; cin >> x >> y;
            yval[y + 10000].push_back(x + 10000);
        }
        set<int> ymid;
        for(int i = 0; i <= 20000; i++){
            if(!yval[i].empty()) sort(yval[i].begin(), yval[i].end());
            for(int j = 0; j < (int)yval[i].size(); j++){
                ymid.insert(yval[i][j] + yval[i][yval[i].size()-1-j]);
            }
        }
        printf("%s\n", ymid.size() == 1 ? "YES" : "NO");
    }
    return 0;
}