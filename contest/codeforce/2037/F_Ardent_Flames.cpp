#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 1e5 + 5;
ll h[MX],x[MX];
ll n,m,k;
void solve(){
    cin>>n>>m>>k;
    ll mmax = 0;
    forn(i,0,n) {cin>>h[i];mmax = max(mmax,h[i]);}
    forn(i,0,n) {cin>>x[i];}
    ll limit = 1e9+1;
    ll l = 0LL,r = limit;
    auto check = [](const int ak)->bool {
        vector<array<ll,2>> cnt;
        for(int i=0;i<n;i++){
            ll t = (h[i] + ak - 1) / ak;
            if(t>m) continue;
            cnt.push_back({x[i]-(m-t),1});
            cnt.push_back({x[i]+(m-t)+1,-1});
        }
        sort(cnt.begin(),cnt.end());
        ll total = 0LL;
        for(auto [_,c] : cnt){
            total += c;
            if(total >= k) return true;
        }
        return false;
    };
    while(r - l > 1){
        ll mid = (r + l) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout<< (r != limit ? r : -1)<<"\n";
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