#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int n,k,x;cin>>n>>k;
    map<int,int> cnt;
    forn(i,0,n){
        cin>>x;
        cnt[x]++;
    }
    vector<int> a;
    for(auto [x,y]:cnt){
        a.push_back(y);
    }
    sort(all(a));
    int ans=0;
    for(int i=0;i<a.size();i++){
        int t = a[i];
        if(k>=t){
            k-=t;
        }else{
            ans++;
        }
    }
    cout<<max(ans,1)<<"\n";
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