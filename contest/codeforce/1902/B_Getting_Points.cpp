#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    ll n,p,l,t;cin>>n>>p>>l>>t;
    ll c1 = (n - 1) / 7 + 1;
    ll c2 = c1 / 2;
    c1 -= c2 * 2;
    vector<ll> s{t*2+l,t+l,l},d{c2,c1,n-c1-c2};
    ll ans = 0LL;
    forn(i,0,3){
        if(s[i] * d[i] >= p){
            ans += (p + s[i] - 1) / s[i];
            break;
        }else{
            ans += d[i];
            p -= s[i] * d[i];
        }
    }
    cout<<(n - ans)<<"\n";
    
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