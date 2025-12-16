#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    ll n,m;cin>>n>>m;
    vector a(n,0);
    string s;cin>>s;
    vector suffix(n-1,0LL);
    for(int i=n-1;i>0;i--){
        if(i<n-1) suffix[i-1] = suffix[i];
        suffix[i-1] += s[i] == '1' ? 1 : -1;
    }
    sort(suffix.begin(),suffix.end(),greater());
    int ans = 0;
    for(int i=0;i<n-1;i++){
        m -= suffix[i];
        if(m<=0){
            cout<<i+2<<"\n";
            return;
        }
    }
    cout<<"-1"<<"\n";
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