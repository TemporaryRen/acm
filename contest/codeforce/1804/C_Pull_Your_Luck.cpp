#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

const int MX = 2e5 + 1;
typedef long long ll;

void solve(){
    int n,x,p;cin>>n>>x>>p;
    int t = n - x;
    forn(i,1,min(p + 1,n*2+1)){
        ll F = (1LL + i) * i / 2;
        if(((F - t) % n) == 0){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
    
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