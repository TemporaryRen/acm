#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int l,r;
    cin>>l>>r;
    vector a(3,0);
    int y = __lg(r);
    for0(i,y,-1){
        sort(all(a));
        int t = 1<<i;
        if(a[0]+t<=r){
            a[0]+=t;
        }
        if(a[1]+t-1 < l){
            a[1]+=t;
        }
        if(a[2]+t-1 < l){
            a[2]+=t;
        }
    }
    sort(all(a));
    if(a[1] == a[0]) a[1]++;
    if(a[2] == a[1]) a[2]++;
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
    //cout<<(a[0] ^ a[1]) + (a[1] ^ a[2]) + (a[0] ^ a[2])<<"\n";
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