#include <bits/stdc++.h>
using namespace std;

const int st = 1001;
vector<int> seq;

void print(){
    for(int i: seq) cout << i << ' ';
}

void ducci(){
    int n = seq.size();
    int first = seq[0];
    for (int i = 0; i < n; i++){
        seq[i] = i < (n - 1) ? abs(seq[i] - seq[(i+1) % n]) : abs(seq[i] - first);
    }
}

bool is0(){
    bool ok = true;
    for (int i = 1; i < (int)seq.size(); i++) ok &= (seq[i] == seq[i-1]);
    return ok;
}


int main(){
    int c;
    cin >> c;
    while(c--){
        int m, x; cin >> m;
        seq.clear();
        while(m--){ cin >> x; seq.push_back(x);}
        bool xun = true;
        for(int i = 0; i < st; i++){
            if(is0()) {xun = false; break;}
            ducci();
        }
        string result = xun ? "LOOP" : "ZERO";
        cout << result << endl;
    }
    return 0;
}