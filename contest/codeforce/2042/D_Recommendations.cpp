#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 2e5 + 4;
struct Node{
    int idx;
    int L;
    int R;
}node[MX];
#define L(x) node[x].L
#define R(x) node[x].R
#define idx(x) node[x].idx
int ans[MX];

void solve(){
    int n;cin>>n;
    fill(ans,ans+n,0);
    for(int i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        L(i) = t1;
        R(i) = t2;
        idx(i) = i;
    }
    set<int> rRange;
    sort(node,node+n,[](const Node& a,const Node& b){
        if(a.L != b.L) return a.L < b.L;
        else return a.R > b.R;
    });
    for(int i=0;i<n;i++){
        auto it = rRange.lower_bound(R(i));
        if(it != rRange.end()){
            ans[idx(i)] += *it - R(i);
        }
        rRange.insert(R(i));
    }
    auto cmp = [](const int a,const int b){
        return a > b;
    };
    set<int,greater<>> lRange;
    sort(node,node+n,[](const Node& a,const Node& b){
        if(a.R != b.R) return a.R > b.R;
        else return a.L < b.L;
    }); 
    for(int i=0;i<n;i++){
        auto it = lRange.lower_bound(L(i));
        if(it != lRange.end()){
            ans[idx(i)] += L(i) - *it;
        }
        lRange.insert(L(i));
    }
    sort(node,node+n,[](const Node& a,const Node& b){
        if(a.L != b.L) return a.L < b.L;
        else return a.R < b.R;
    });
    for(int i=0;i<n;i++){
        if(i<n-1 && L(i) == L(i+1) && R(i) == R(i+1)){
            ans[idx(i)] = 0;
            ans[idx(i+1)] = 0;
        }
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<"\n";
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