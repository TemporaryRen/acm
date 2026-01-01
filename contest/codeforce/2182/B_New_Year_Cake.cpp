#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    vector<int> a(2),b(2);
    forn(i,0,2) {
        cin>>a[i];
        b[i] = a[i];
    }
    int p =  1;
    int ans1 = 0;
    int tot = 1;
    while(a[p] >= tot){
        ans1++;
        a[p] -= tot;
        tot <<= 1;
        p ^= 1;
    }
    int ans2 = 0;
    p =0;
    tot = 1;
    while(b[p] >= tot){
        ans2 ++;
        b[p] -= tot;
        tot <<= 1;
        p ^= 1;
    }
    cout<<max(ans1,ans2)<<"\n";

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