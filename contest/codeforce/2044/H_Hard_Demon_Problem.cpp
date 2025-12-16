#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    int n,q,x;
    cin>>n>>q;
    vector prefix(n,vector(n+1,0LL));
    vector ret(n,vector(n+1,0LL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            prefix[i][j+1] = prefix[i][j] + x;
            ret[i][j+1] = ret[i][j] + (j+1) * x;
        }
    }
    vector retPre(n+1,vector(n+1,0LL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            retPre[i+1][j+1] = retPre[i][j+1] + ret[i][j+1];
        }
    }
    vector prefixPre(n+1,vector(n+1,0LL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            prefixPre[i+1][j+1] = prefixPre[i][j+1] + prefix[i][j+1];
        }
    }

    vector xPrefixPre(n+1,vector(n+1,0LL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            xPrefixPre[i+1][j+1] = xPrefixPre[i][j+1] + (i * prefix[i][j+1]);
        }
    }
    
    auto cal = [&](const int t,const int b,const int c1,const int c2,const vector<vector<ll>>& pre) -> ll{
        return pre[t+1][c1+1] - pre[b][c1+1] - pre[t+1][c2] + pre[b][c2];
    };
    while(q--){
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        lx--;
        ly--;
        rx--;
        ry--;
        ll ans = 0LL;
        //(ry-ly+1) * (i-lx) - ly
        ll c1 = (ll)ry - ly + 1;
        ll c2 = c1 * lx + ly;
        ll c3 = cal(rx,lx,ry,ly,retPre);
        ll c4 = c2 * cal(rx,lx,ry,ly,prefixPre);
        ll c5 = c1 * cal(rx,lx,ry,ly,xPrefixPre);
        cout<<c5 + c3-c4<<" "; 
    }
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