#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    ll n,x,y,total=0LL;cin>>n>>x>>y;
    vector<int> a(n);
    forn(i,0,n) {
        cin>>a[i];
        total += a[i];
    }
    ll R = total - x;
    ll L = total - y;
    sort(a.begin(),a.end());
    ll ans = 0;
    for(int l=0;l<n-1;l++){
        ll x1 = a[l];
        int ansL = n;
        int lo = l,hi = n;  
        while(lo < hi - 1){
            int mid = (lo + hi) / 2;
            //cout<<mid<<"\n";
            ll y1 = a[mid];
            if(x1+y1>=L) hi = mid;
            else lo = mid;
        }
        if(hi != n) ansL = hi;
        int ansR = l;
        lo = l,hi = n;
        while(lo < hi - 1){
            int mid = (lo + hi) / 2;
            ll y1 = a[mid];
            if(x1+y1 <= R) lo = mid;
            else hi = mid;
        }
        if(lo != l) ansR = lo;
        //cout<<ansL<<" "<<ansR<<"\n";
        ans += max(0,ansR - ansL + 1);
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