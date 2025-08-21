#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
const int MX = 5005;;
struct item{
    int val;
    int pos;
}items[MX];
int source[MX];
int n;
void solve(){
    int k;cin>>n>>k;
    forn(i,0,n){
        cin>>items[i].val;
        source[i] = items[i].val;
        items[i].pos = i;
    }
    vector pre(n,0),suf(n,n-1);
    forn(i,1,n){
        if(source[pre[i-1]] < source[i-1]){
            pre[i] = i - 1;
        }else{
            pre[i] = pre[i-1];
        }
    }
    for0(i,n-2,-1){
        if(source[suf[i+1]] < source[i+1]){
            suf[i] = i + 1;
        }else suf[i] = suf[i+1];
    }
    sort(items,items+n,[](item a, item b){
        return a.val > b.val;
    });
    ll ans = 0LL;

    forn(i,0,n){
        ll t = source[i];
        set choosed{i};
        int left = k;
        int need = 0 + (i>0) + (i<n-1);
        if(need > left) continue;
        if(i > 0){
            left--;
            choosed.insert(pre[i]);
            t += source[pre[i]];
        }
        if(i < n-1){
            left--;
            choosed.insert(suf[i]);
            t += source[suf[i]];
        }
        forn(j,0,n){
            if(left == 0) break;
            if(choosed.find(items[j].pos) != choosed.end()) continue;
            t += items[j].val;
            left --;
        }
        ans = max(ans,t);
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