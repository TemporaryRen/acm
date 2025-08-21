#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()

const ll MX = 1e17 + 5;
void solve(){
    ll x,y;cin>>x>>y;
    auto cal = [&](ll a,ll b,ll mask)->ll{
        ll lo = 2,hi = MX;
        while(lo < hi){
            while(lo < hi){
                int mid = lo + (hi - lo) / 2;
                if(mid%2 != 0) mid ++;
                if(b / mid <= a){
                    hi = mid;
                }else{
                    lo = mid + 2;
                }
            }
            if(mask&hi != 0){
                lo = hi + 1;
                hi = MX;
            }
        }
        return hi;
    };
    ll ans = 0LL;
    ll mask = 0LL;
    while(x != y){
        if(x > y) swap(x,y);
        ll t = cal(x,y,mask);
        ans += t;
        y /= t;
        mask |= t;
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