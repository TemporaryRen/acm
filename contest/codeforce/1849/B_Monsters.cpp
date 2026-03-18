#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n,k; cin>>n>>k;
    vector a(n,0);
    forn(i,0,n){
        cin>>a[i];
        a[i] %= k;
        if(a[i] == 0) a[i] = k;
    }
    vector<int> ans(n);
    iota(all(ans),1);
    stable_sort(all(ans),[&](const int o1,const int o2){return a[o1-1] > a[o2-1];});
    forn(i,0,n) cout<<ans[i]<<" ";
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