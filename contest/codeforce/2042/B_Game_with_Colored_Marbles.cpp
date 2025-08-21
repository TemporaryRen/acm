#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 10001;
int cnt[MX];
void solve(){
    int n;cin>>n;
    fill(cnt,cnt+MX,0);
    forn(i,0,n){
        int x;cin>>x;
        cnt[x] ++;
    }
    bool t = true;
    int ans = 0;
    forn(i,1,MX){
        if(cnt[i] == 1){
            ans += t ? 2 : 0;
            t = !t;
        }else if(cnt[i] > 1) ans+=1;
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