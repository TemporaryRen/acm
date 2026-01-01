#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector a(3,vector<int>(n,0));
    forn(c,0,3){
        forn(i,0,n){
            cin>>a[c][i];
        }
    }
    ll ans1= 0LL,ans2 = 0LL;
    auto check = [&](const vector<int> x,const vector<int> y,const int offset) -> bool{
        forn(i,0,n){
            if(x[i] <= y[(i+offset)%n]) return false;
        }
        return true;
    };
    forn(i,0,n){
        
        if(check(a[1],a[0],i)) ans1++;
        if(check(a[2],a[1],i)) ans2++;
        
    }
    cout<<(ans1 * ans2 * n) <<"\n";
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