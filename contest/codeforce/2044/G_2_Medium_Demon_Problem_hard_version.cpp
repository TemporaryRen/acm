#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    int n,x;cin>>n;
    vector g(n,vector<int>());
    vector rg(n,vector<int>());
    vector indgree(n,0);
    for(int i=0;i<n;i++){
        cin>>x;
        x--;
        g[i].push_back(x);
        indgree[x] ++;
    }
    vector<int> q;
    for(int i=0;i<n;i++){
        if(indgree[i] == 0){
            q.push_back(i);
        }
    }
    while(!q.empty()){
        auto nq = q;
        q = {};
        for(auto cur : nq){
            for(auto nxt : g[cur]){
                rg[nxt].push_back(cur);
                if(!(--indgree[nxt])) q.push_back(nxt);
                
            }
        }
    }
    auto maxLink = [&](auto &self,const int curr) -> int {
        int t = 1;
        for(auto nxt : rg[curr]) t += self(self,nxt);
        return t;
    };

    int ans = 0;
    for(int i=0;i<n;i++){
        if(indgree[i] != 0){
            for(auto nxt : rg[i])
                ans = max(ans,maxLink(maxLink,nxt));
        }
    }
    cout<<ans+2<<"\n";
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