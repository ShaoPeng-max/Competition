#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
vector<string> filenames;

void print(const string& s, int len, char extra){
    cout << s;
    for (int i = 0; i < len - s.length(); i++){
        cout << extra;
    }
}

int main(){
    int n;
    while(cin >> n){
        string file;
        int M = 0;
        filenames.clear();
        for(int i = 0; i < n; i++){
            cin >> file;
            M = max(M, (int)file.length());
            filenames.push_back(file);
        }
        sort(filenames.begin(), filenames.end());
        int col = ((60 - M) / (M + 2)) + 1;
        int row = (n + col - 1) / col;
        print("", 60, '-');
        cout << endl;
        for (int i = 0; i < row; i++){
            for (int j = i; j <= (i + row * (col - 1)); j += row){
                if (j < n)
                    print(filenames[j], j == (i + row*(col-1)) ? M : M+2, ' ');
                // cout << j << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}