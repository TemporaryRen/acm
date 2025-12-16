#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)
set<int> happy;

void solve(){
    int n;
    cin>>n;
    int ans = 0;
    int t = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        t += x;
        if(happy.count(t)) ans ++;
        
    }
    cout<<ans<<"\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for(int i=1;i<100;i+=2){
        happy.insert(i*i);
    }
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}