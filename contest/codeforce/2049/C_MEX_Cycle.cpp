#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,x,y;cin>>n>>x>>y;
    x--;y--;
    if(x>y) swap(x,y);
    vector<int> a(n);
    if(n%2){
        forn(i,0,n){
            if(i<x) a[i] = i%2;
            else if(i==x) a[i] = 2;
            else a[i] = (i%2)^1;
        }
    }else{
        forn(i,0,n){
            if(i==x && (x%2 == y%2)) a[i] = 2;
            else a[i] = i%2;
        }
    }
    for(auto x : a) cout<<x<<" ";
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