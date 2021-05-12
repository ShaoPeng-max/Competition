#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

const int n = 10005;
const int m = 15;
int pnf[m][n];
map<string, int> rec;
int s;

int ID(const string& ss){
    if(rec.count(ss)) return rec[ss];
    return rec[ss] = s++;

}

int main(){
    int row, col;
    while(scanf("%d%d", &row, &col) == 2 && row){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) pnf[i][j] = 0;
        }
        s = 0; rec.clear();
        int cnt = 0;
        string te = "";
        while(cnt < row * col){
            char c = getchar();
            if (c != ',' && c != '\n') te += c;
            if ((c == ',' || c == '\n') && te.length() != 0){
                int r = cnt / col, c = cnt % col;
                pnf[r][c] = ID(te);
                cnt++;
                te.clear();
            } 
        }
        bool ok = true;
        for (int i = 0; i < col - 1 && ok; i++){
            map<pair<int, int>, int> res;
            int r = 0;
            for (int j = i + 1; j < col && ok; j++){
                res[make_pair(pnf[0][i], pnf[0][j])] = r++;
                for (int k = 1; k < row && ok; k++){
                    pair<int, int> pa = make_pair(pnf[k][i], pnf[k][j]);
                    if (res.count(pa)){
                        cout << "NO" << endl;
                        cout << res[pa]+1 << ' ' << k+1 << endl;
                        cout << i+1 << ' ' << j+1 << endl;
                        ok = false;
                    }
                    res[pa] = r++;
                }
            }
        }
        if(ok) cout << "YES" << endl;
    }
    return 0;
}