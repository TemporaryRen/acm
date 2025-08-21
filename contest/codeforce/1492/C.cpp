#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int n,m;cin>>n>>m;
    string s,t; cin>>s>>t;
    vector pre(m,0),suf(m,0);
    int p = 0;
    forn(i,0,n){
        if(s[i] == t[p]){
            pre[p] = i;
            p++;
        }
    }
    p--;
    for0(i,n-1,-1){
        if(s[i] == t[p]){
            suf[p] = i;
            p--;
        }
    }
    int ans = 0;
    forn(i,1,m){
        ans = max(ans,suf[i] - pre[i-1]);
    }
    cout<<ans<<"\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}