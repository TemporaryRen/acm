#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector a(n,0LL);
    ll llcm = 1LL;
    forn(i,0,n){
        cin>>a[i];
        llcm = llcm * a[i] / __gcd(a[i],llcm);
    }
    vector<int> ans(n);
    ll total = 0LL;
    forn(i,0,n){
        ans[i] = llcm / a[i];
        total +=  ans[i];
    }
    if(total < llcm){
        forn(i,0,n) cout<<ans[i]<<" ";
    }else cout<<-1;

    cout<<"\n";
    
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