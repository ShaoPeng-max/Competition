#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> Map;
Map rec;

int main(){
    string s;
    while(cin >> s){
        rec[s] = 1;
    }
    for(Map::iterator it = rec.begin(); it != rec.end(); it++){
        for(int i = 1; i < it->first.size() - 1; i++){
            string s1 = it->first.substr(0, i), s2 = it->first.substr(i);
            if(rec.count(s1) && rec.count(s2)) {cout << it->first << endl; break;}
        }
    }
    return 0;
}