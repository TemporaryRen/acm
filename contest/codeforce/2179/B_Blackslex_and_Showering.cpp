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
    int ans = 0;
    forn(i,0,n){
        cin>>a[i];
    } 
    forn(i,1,n){
        ans += abs(a[i-1] - a[i]);
    }
    int mmax = 0;
    forn(i,0,n){
        int cur = 0;
        if(i == 0) cur = abs(a[i] - a[i+1]);
        else if(i == n - 1) cur = abs(a[i-1] - a[i]);
        else if((a[i] - a[i+1]) * (a[i-1] - a[i]) < 0) cur = abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]) - abs(a[i-1] - a[i+1]);
        mmax = max(cur,mmax);
    }
    ans -= mmax;
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