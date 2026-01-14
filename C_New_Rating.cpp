#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector a(n,0),b(n,0);
    int pre = 0;
    forn(i,0,n){
        cin>>a[i];
        if(a[i] > pre) b[i] = -1;
        if(a[i] < pre) b[i] = 1;
        pre = a[i];
    }

    int l = 0;
    int tot = 0;
    forn(i,0,n){
        if(tot < 0){
            l = i;
            tot = 0;
        }else{
            tot += b[i];
        }
    }


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