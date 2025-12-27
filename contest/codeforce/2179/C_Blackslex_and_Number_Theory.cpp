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
    sort(all(a));
    int ans = a[0];
    bool f = true;
    forn(i,1,n){
        if(a[i] == ans * 2){
            f = false;
            break;
        }
    }
    if(f) ans = max(ans,a[1] - a[0]);
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