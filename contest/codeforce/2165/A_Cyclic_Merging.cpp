#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector a(n+1,0);
    forn(i,0,n) cin>>a[i];
    int mmax = -1,p = -1;
    forn(i,0,n){
        if(a[i] > mmax){
            p = i;
            mmax = a[i];
        }
    }
    ll ans = 0LL;
    int start = p + 1;
    while(start%n != p){
        ans += max(a[start%n],a[(start+1)%n]);
        start += 1;
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