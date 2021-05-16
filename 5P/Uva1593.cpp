#include <bits/stdc++.h>
using namespace std;

string code[1005][185];
int just[185];
int m[1005];

void print(const string& word, int len){
    cout << word;
    for (int i = 0; i < len - word.length(); i++){
        cout << ' ';
    }
}

int main(){
    string inputs, s, word;
    memset(just, 0, sizeof(just));
    int i = 0, j;
    while(getline(cin, inputs)){
        j = 0;
        stringstream s(inputs);
        while(s >> word){
            code[i][j] = word;
            just[j] = max(just[j], (int)word.length());
            j++;
        }
        m[i] = j;
        i++;
    }
    for(int r = 0; r < i; r++){
        for (int c = 0; c < m[r] - 1; c++){
            print(code[r][c],just[c] + 1);
        }
        cout << code[r][m[r]-1] << endl;
    }
    return 0;
}