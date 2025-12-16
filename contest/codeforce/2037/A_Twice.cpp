#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    map<int,int> cnt;
    int ans = 0;
    forn(i,0,n){
        int x;cin>>x;
        if(cnt[x] > 0){
            ans ++;
            cnt[x] --;
        }else{
            cnt[x]++;
        }
    }
    cout<<ans<<"\n";
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