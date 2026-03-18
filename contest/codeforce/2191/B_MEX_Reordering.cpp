#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    int cnt0 = 0, cnt1 = 0;
    forn(i,0,n){
        int t;cin>>t;
        if(t == 0) cnt0++;
        if(t == 1) cnt1++;
    }
    if(cnt0 == 1 || cnt0 > 1 && cnt1 > 0) cout<<"YES\n";
    else cout<<"NO\n";

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