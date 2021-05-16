#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    for(;;){
        cin >> n;
        if(!n) break;
        deque<int> q;
        vector<int> discard;
        for(int i = 1; i <= n; i++) q.push_back(i);
        while(q.size() >= 2){
            discard.push_back(q.front());
            q.pop_front();
            q.push_back(q.front());
            q.pop_front();
        }
        cout << "Discarded cards:";
        if(discard.size() > 0) cout << ' ' << discard[0]; 
        for (int i = 1; i < (int)discard.size(); i++) cout << ", " << discard[i];
        cout << "\nRemaining card: " << q.front() << endl;
    }
    return 0;
}