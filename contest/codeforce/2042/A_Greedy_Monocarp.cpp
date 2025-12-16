#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    forn(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        if(a[i]>k) break;
        k -= a[i];
    }
    ans += k;
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