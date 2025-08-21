#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    int n,x;
    cin>>n;
    vector<int> typo(n,0);
    vector g(n,vector<int>());
    for(int i=0;i<n;i++){
        cin>>x;
        x--;
        typo[x] ++;
        g[i].push_back(x);
    }
    vector<int> q;
    for(int i=0;i<n;i++){
        if(typo[i] == 0){
            q.push_back(i);
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto nq = q;
        q = {};
        for(auto cur : nq){
            for(auto nxt : g[cur]){
                typo[nxt] --;
                if(!typo[nxt]) q.push_back(nxt);
            }
        }
        ans ++;
    }
    cout<<ans + 2<<"\n";

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}