#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    ll ans = 0LL,tot = 0LL;
    forn(i,0,n){
        cin>>a[i];
        ans += abs(a[i]);
    }
    int c = 0,mmin = 1e9 + 1;
    forn(i,0,n){
        if(a[i] <= 0){
            c ++;
        }
        mmin = min(abs(a[i]),mmin);
    }
    if(c&1) ans -= 2*mmin;
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