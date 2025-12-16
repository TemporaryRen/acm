#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,k;cin>>n>>k;
    int mod = 1e9 + 7;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll xmax = 0;
    ll x = 0LL;
    ll sum = 0LL;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(x+a[i] > 0) x += a[i];
        else x = 0;
        xmax = max(xmax,x);
    }
    sum -= xmax;
    for(int i=0;i<k;i++){
        xmax = (xmax * 2) % mod;
    }
    sum += xmax;
    while (sum < 0) sum += mod;
    cout<<sum<<"\n";


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