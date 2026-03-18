#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector a(n,0);
    vector prefix(n+1,0LL);
    forn(i,0,n) cin>>a[i];
    sort(all(a));
    forn(i,0,n){
        prefix[i+1] = prefix[i] + a[i];
    }
    int target = n;
    forn(i,0,n){
        if(a[i] > 0 && prefix[n] - prefix[i] - (n - i) >= target - 1){
            cout<<(n - i)<<"\n";
            return;
        }
        target -= a[i];
    }
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