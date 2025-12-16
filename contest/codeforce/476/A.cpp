#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int n,m;cin>>n>>m;
    int l = n/2,r = n;
    if(n&1) l++;
    for(int i=l;i<=r;i++){
        if(i%m==0){
            cout<<i<<"\n";
            return;
        }
    }
    cout<<-1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}