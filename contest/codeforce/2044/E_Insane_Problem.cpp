#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    ll k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    vector<ll> kk;
    kk.push_back(1);
    kk.push_back(k);
    ll start = (ll)k;
    if(k>=2){
        while(start*k<=r2){
            kk.push_back(start*k);
            start *= k;
        }
    }
    ll ans = 0;
    ll n = kk.size();
    for(ll i=0;i<n;i++){
        ll R = r1+1,L = l1;
        ll t = kk[i];
        while(L<R){
            int mid = (R + L) / 2;
            if(t*mid <= r2){
                L = mid + 1;
            }else{
                R = mid;
            }
        }
        if(L == l1) continue;
        ll r = L - 1;
        R = r1+1,L = l1;
        while(L<R){
            int mid = (R + L) / 2;
            if(t*mid < l2){
                L = mid + 1;
            }else{
                R = mid;
            }
        }
        if(R < L) continue;
        ll l = R;
        ans += r - l + 1;
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