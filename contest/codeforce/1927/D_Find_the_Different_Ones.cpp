#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    forn(i,0,n) cin>>a[i];
    vector<pair<int,int>> range;
    vector<int> b;
    int l = 0;
    forn(r,0,n){
        if(a[r] != a[l]){
            range.push_back({l,r});
            b.push_back(r-1);
            l = r;
        }
    }
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        x--;y--;
        auto iter = lower_bound(all(b),x);
        if(iter == b.end()) cout<<-1<<" "<<-1<<"\n";
        else{
            int p = iter - b.begin();
            if(range[p].second <= y){
                cout<<(x+1)<<" "<<range[p].second+1<<"\n";
            }else{
                cout<<-1<<" "<<-1<<"\n";
            }
        }
        
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