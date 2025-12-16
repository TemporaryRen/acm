#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int a1 = min(m,a);
    int b1 = min(m,b);
    cout<<(a1+b1+min(m*2-a1-b1,c))<<"\n";
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