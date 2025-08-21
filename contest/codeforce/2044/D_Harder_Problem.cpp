#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    int n;cin>>n;
    vector<int> ans(n,-1),pos(n+1,-1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(pos[x] == -1) pos[x] = i;
    }
    for(int i=1;i<=n;i++){
        if(pos[i] != -1) ans[pos[i]] = i;
    }
    int fill = 1;
    for(int i=0;i<n;i++){
        if(ans[i] == -1){
            while(pos[fill] != -1) fill ++;
            ans[i] = fill++;
        }
    }
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