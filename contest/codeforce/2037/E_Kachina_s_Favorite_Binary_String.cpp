#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;
    cin>>n;
    int l,r;
    ll v;
    l = 1 ,r = n;
    int r1 = n;
    int l1 = n-1;
    int oneCnt = 0;
    vector<int> onePos;
    ll total = 0;
    while(l1 > 0){
        cout<<"? "<<l1<<" "<<n<<endl;
        cin>>v;
        int posLen = onePos.size();
        if(v - total > onePos.size()){
            for(int i=l1+1;i-l1<=(v - total - posLen);i++) onePos.push_back(i);
        }else if(v == total && total > 0){
            onePos.push_back(l1);
        }
        l1 --;
        total = v;
    }
    if(onePos.empty()){
        cout<<"! IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> ans(n,0);
    for(auto x : onePos) ans[x-1] = 1;
    cout<<"! ";
    for(auto x: ans) cout<<x;
    cout<<endl;
    
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
