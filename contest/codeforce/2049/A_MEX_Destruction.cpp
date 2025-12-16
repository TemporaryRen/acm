#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    forn(i,0,n) cin>>a[i];
    bool f1 = false,f2 = false,f3 = false;
    for(int i=0;i<n;i++){
        if(a[i] > 0) {
            f1 = true;
            if(f2) f3 = true;
        }
        else if(f1) f2 = true; 
    }
    if(f3) cout<<2;
    else if(f1) cout<<1;
    else cout<<0;
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