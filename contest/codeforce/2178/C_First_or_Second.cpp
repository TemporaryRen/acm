#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector<int> a(n);
    forn(i,0,n) cin>>a[i];
    vector pre_sum(n+1,0LL),pre_sum2(n+1,0LL);
    forn(i,0,n){
        pre_sum[i+1] = pre_sum[i] + abs(a[i]);
        pre_sum2[i+1] = pre_sum2[i] + a[i];
    }
    ll ans = pre_sum2[1] - pre_sum2[n];
    forn(i,1,n){
        ans = max(ans,pre_sum[i] - pre_sum[1] - pre_sum2[n] + pre_sum2[i+1] + a[0]);

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