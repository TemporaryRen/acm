#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
void solve(){
    int n,m,L;
    cin>>n>>m>>L;
    vector<pair<int,int>> bounds(n);
    for(int i=0;i<n;i++){
        cin>>bounds[i].first;
        cin>>bounds[i].second;
    }
    queue<pair<int,int>> power;
    forn(i,0,m){
        int x,v;cin>>x>>v;
        power.push({x,v});
    }
    priority_queue<int,vector<int>,less<int>> p;
    ll total = 1LL;
    int ans = 0;
    forn(i,0,n){
        int l = bounds[i].first;
        int r = bounds[i].second;

        while(!power.empty() && power.front().first < l){
        
            p.push(power.front().second);
            power.pop();
        }
        int distinct = r - l + 2;
        while(total < distinct && !p.empty()){
            total += p.top();
            p.pop();
            ans ++;
        }
        if(total < distinct){
            cout<<-1<<"\n";
            return;
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