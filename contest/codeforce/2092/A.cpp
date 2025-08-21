#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int n,t,mmax = 0,mmin = 1e9 + 5;
    cin>>n;
    forn(i,0,n){
        cin>>t;
        mmax = max(mmax,t);
        mmin = min(mmin,t);
    }
    cout<<mmax - mmin<<"\n";
    
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