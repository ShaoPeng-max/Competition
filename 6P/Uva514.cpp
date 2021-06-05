#include <bits/stdc++.h>
using namespace std;

int target[1005];

int main(){
    int num;
    while(scanf("%d", &num) == 1 && num){
        bool ok1 = true;
        while(ok1){
            for(int i = 1; i <= num && ok1; i++){
                scanf("%d", &target[i]);
                if(target[i] == 0) ok1 = false;
            }
            if(!ok1) break;
            int a = 1;
            stack<int> s;
            for(int b = 1; b <= num; b++){
                s.push(b);
                while(!s.empty() && s.top() == target[a]){
                    a++;
                    s.pop();
                }
            }
            printf("%s\n", s.empty() ? "Yes" : "No");
        }
        printf("\n");
    }
}