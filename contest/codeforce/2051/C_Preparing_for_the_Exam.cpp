#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector ans(m,0);
    vector<int> q(m);
    vector<int> a(k);
    forn(i,0,m) cin>>q[i];
    set<int> t;
    forn(i,0,k){
        int x;cin>>x;
        t.insert(x);
    }
    if(k==n){
        forn(i,0,m) cout<<1;
        cout<<"\n";
        return;
    }
    if(k<n-1){
        forn(i,0,m) cout<<0;
        cout<<"\n";
        return;
    }
    set<int> tt;
    forn(i,1,n+1){
        if(t.find(i) == t.end()){
            tt.insert(i);
        }
    }
    if(k >= m-1){
        forn(i,0,m){
            int x = q[i];
            if(tt.count(x)) ans[i] = 1;
        }
    }
    for(auto x : ans) cout<<x;
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