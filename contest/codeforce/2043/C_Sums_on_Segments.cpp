#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()


void solve(){
    int n;cin>>n;
    vector<int> a(n);
    int pos = 0;
    forn(i,0,n){
        cin>>a[i];
        if(a[i] != 1 && a[i] != -1) pos = i;
    }
    int l = 0,r = 0;
    vector<ll> ans;
    ans.push_back(0LL);
    forn(i,0,pos){
        if(a[i] == 1){
            r += 1;
            if(l<0) l += 1;
            ans.push_back((ll)r);
        }else{
            if(r>0) r -= 1;
            l -= 1;
            ans.push_back((ll)l);
        }
    }
    int l2 = 0,r2 = 0;
    for0(i,n-1,pos){
        if(a[i] == 1){
            r2 += 1;
            if(l2<0) l2 += 1;
            ans.push_back((ll)r2);
        }else{
            if(r2>0) r2 -= 1;
            l2 -= 1;
            ans.push_back((ll)l2);
        }
    }
    ans.push_back((ll)a[pos]);
    forn(i,l+l2,r+r2+1){
        ans.push_back((ll)i + a[pos]);
    }
    sort(all(ans));
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout<<ans.size()<<"\n";
    for(auto x : ans) cout<<x<<" ";
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