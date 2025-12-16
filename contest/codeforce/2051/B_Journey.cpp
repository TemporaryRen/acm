#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    ll n,a,b,c;cin>>n>>a>>b>>c;
    ll total = a + b + c;
    ll ans = n / total;
    ll l = n - ans * total;
    ans *= 3;
    if(l > a + b) ans += 3;
    else if(l > a) ans += 2;
    else if(l > 0) ans+= 1;
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