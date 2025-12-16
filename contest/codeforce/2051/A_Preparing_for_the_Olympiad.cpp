#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    forn(i,0,n) cin>>a[i];
    forn(i,0,n) cin>>b[i];
    int ans = 0;
    forn(i,0,n){
        if(i==n-1) ans += a[i];
        else{
            if(a[i]-b[i+1] > 0) ans += a[i]-b[i+1];
        }
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