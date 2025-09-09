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
    map<int,int> cnt;
    for(auto x : a){
        cnt[x] ++;
    }
    for(auto x : a){
        if(cnt[x]%x != 0){
            cout<<-1<<"\n";
            return;
        }
    }
    map<int,int> mmp;
    cnt.clear();
    vector<int> ans(n);
    int start = 1;
    forn(i,0,n){
        int x = a[i];
        if(mmp.find(x) == mmp.end() || cnt[mmp[x]] == x){
            mmp[x] = start++;
        }
        ans[i] = mmp[x];
        cnt[ans[i]] ++;
    }
    forn(i,0,n) cout<<ans[i]<<" ";
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