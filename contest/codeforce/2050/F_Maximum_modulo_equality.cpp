#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)
const int MX = 2e5 + 2;
int tree[MX<<2],n,q;
int b[MX];
void pushUp(int curr){
    int l = curr << 1;
    int r = curr << 1 | 1;
    tree[curr] = __gcd(tree[l],tree[r]);
}

void build(int curr=1,int l=1,int r = n-1){
    if(l>r) return;
    if(l==r){
        tree[curr] = b[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(curr<<1,l,mid);
    build(curr<<1|1,mid+1,r);
    pushUp(curr);
}
int query(int curr,int l,int r,int start=1,int end=n-1){
    if(l>r) return 0;
    if(l<=start && r>=end){
        return tree[curr];
    }
    int mid = start + (end - start) / 2;
    if(l>mid) return query(curr<<1|1,l,r,mid+1,end);
    if(r<=mid) return query(curr<<1,l,r,start,mid);
    return __gcd(query(curr<<1|1,l,r,mid+1,end),query(curr<<1,l,r,start,mid));
}
void solve(){
    cin>>n>>q;
    vector<int> a(n);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        b[i] = abs(a[i+1] - a[i]); 
    }
    for(int i=1;i<n;i++) cout<<b[i];
    build();
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<query(1,x,y-1)<<" ";
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