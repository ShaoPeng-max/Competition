#include <map>
#include <queue>
#include <cstdio>
using namespace std;

const int maxt = 1010;

int main(){
    int t, kase = 0;
    while(scanf("%d", &t) == 1 && t){
        printf("Scenario #%d\n", ++kase);

        // 记录团队编号
        map<int, int> team;
        for (int i = 0; i < t; i++){
            int n, x;
            scanf("%d", &n);
            while(n--) {scanf("%d", &x); team[x] = i;}
        }
        
        // 模拟
        queue<int> q1, q2[maxt];
        for(;;){
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if(cmd[0] == 'S') break;
            else if (cmd[0] == 'D'){
                int t = q1.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty()) q1.pop();
            }
            else if (cmd[0] == 'E'){
                scanf("%d", &x);
                int t = team[x];
                if (q2[t].empty()) q1.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}