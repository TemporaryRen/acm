#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int n,m,q;cin>>n>>m>>q;
    vector<pair<int,int>> seg({{1,0},{m,m},{n+1,n}});
    while (q--){
        int x;cin>>x;
        bool lf = seg[0].first <= x && seg[0].second >=x;
        bool rf = seg[2].first <= x && seg[2].second >=x;
        bool ins = false;
        for(auto& [l,r] : seg){
            if(r < l) continue;
            if(l<=x && r>=x){
                ins = true;
                if(l == r){
                    l = n + 1;
                    r = 0;
                }
            }
            else if(x<l) l-=1;
            else r+=1;
        }
        if(ins){
            if(!lf){
                if(seg[0].second == 0)
                    seg[0].second += 1;
            }else {
                seg[0].second = max(1,seg[0].second);
                seg[0].first = 1;
            }
            if(!rf){
                if(seg[2].first == n+1)
                    seg[2].first -= 1;
            }else{
                seg[2].first = min(n,seg[2].first);
                seg[2].second = n;
            }
        } 
        
        int ans = 0;
        int R = 0;
        for(auto&[l,r]:seg){
            if(r>=l){
                if(r>R){
                    ans += r - max(l,R+1) + 1;
                }
                R = max(R,r);
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";

}


int main(){
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