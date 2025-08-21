#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()

void solve(){
    int n,d;cin>>n>>d;
    cout<<1<<" ";
    if(d%3==0 || n>=3)  cout<<3<<" ";
    if(d==5) cout<<5<<" ";
    if(d==7 || n>=3) cout<<7<<" ";
    if(d == 9 || ((d==3 || d== 6) && n>=3) || n>=6) cout<<9<<" ";
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