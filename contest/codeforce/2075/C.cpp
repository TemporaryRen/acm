#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()

void solve(){
    ll n,m;cin>>n>>m;
    vector paints(m,0);
    forn(i,0,m) cin>>paints[i];
    sort(all(paints));
    ll ans = 0;
    forn(i,1,n){
        int t1 = lower_bound(all(paints),i) - paints.begin();
        int t2 = lower_bound(all(paints),n-i) - paints.begin();
        if(t1 == m || t2 == m) continue;
        if(t1 > t2) swap(t1,t2);
        ans += (ll)(m-t2) * (m-t1-1);
    }
    cout<<ans<<"\n";
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