#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;cin>>n;
    ll sum = 0,x;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>x;
        a[i] = x;
        sum += x;
    }
    if(sum%n) {
        cout<<"NO\n";
        return;
    }
    ll t = sum / n;
    for(int i=1;i<n-1;i++){
        a[i+1] += a[i-1] - t;
    }
    if(a[n-1] == t){
        cout<<"YES\n";
    }else cout <<"NO\n";
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