#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int> > mat;

int main(){
    int n_mat; cin >> n_mat;
    for(int i = 0; i < n_mat; i++){
        char alpha; int m, n;
        cin >> alpha >> m >> n;
        mat[alpha] = make_pair(m, n);
    }
    string calc;
    while(cin >> calc){
        bool ok = true;
        long long ret = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i < calc.length() && ok; i++){
            if(calc[i] == '(') continue;
            if('A' <= calc[i] && calc[i] <= 'Z') s.push(mat[calc[i]]);
            if(calc[i] == ')'){
                pair<int, int> cur = s.top(); s.pop();
                if(cur.first != s.top().second){ok = false; break;}
                else{ret += s.top().first * cur.first * cur.second; s.top().second = cur.second;}
            }
        }
        if(ok) cout << ret << endl;
        else cout << "error" << endl;
    }
    return 0;
}