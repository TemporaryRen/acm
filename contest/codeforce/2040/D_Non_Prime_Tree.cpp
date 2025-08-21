#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,u,v;
    cin>>n;
    vector g(n,vector<int>());
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(n);
    int cur = 1;
    auto dfs = [&](auto &&self,int x,int p = -1)-> void {
        ans[x] = cur;
        bool isFirst = true;
        for(auto nxt : g[x]){
            if(nxt == p) continue;
            if(isFirst){
                cur ++;
                self(self,nxt,x);
                cur ++;
            }else{
                cur += 2;
                self(self,nxt,x);
            }
            isFirst = false;
        }
    };
    dfs(dfs,0);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
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