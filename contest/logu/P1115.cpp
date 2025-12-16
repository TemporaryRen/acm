/*
The original author is a content creator on Bilibil 
see about https://www.bilibili.com/video/BV1sCUYYYE14?spm_id_from=333.788.videopod.sections&vd_source=82bb775fb6a7ce6a29bd3e3509220efd

*/ 

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define fl(l, r) for(int i=l;i<=r;i++)
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) (x<<1)|1

constexpr int N = 2e5 + 10;
ll a[N];
int n;
struct Info{
    ll ans,pre,suf,sum;
    void operator=(const ll val){
        ans = pre = suf = sum = val;
    }
};

Info operator+(const Info& L, const Info &R){
    Info res;
    res.pre = max(L.pre,L.sum + R.pre);
    res.suf = max(R.suf,L.suf + R.sum);
    res.sum = L.sum + R.sum;
    res.ans = max({L.ans,R.ans,L.suf + R.pre});
    return res;
};

struct Node{
    Info info;
} node[N << 2];

#define info(x) node[x].info
#define ans(x) info(x).ans

inline void pushUp(const int curr){
    info(curr) = info(ls(curr)) + info(rs(curr));
}

inline Info query(const int curr,const int l,const int r,const int s = 1,const int e = n){
    if(l<=s and e>=r) return info(curr);
    const int mid = s+e>>1;
    if(l>mid) return query(rs(curr),l,r,mid+1,e);
    if(r<=mid) return query(ls(curr),l,r,s,mid);
    return query(rs(curr),l,r,mid+1,e) + query(ls(curr),l,r,s,mid);
}

inline void build(const int curr = 1,const int l = 1,const int r = n){
    if(l==r){
        info(curr) = a[l];
        return;
    }
    const int mid = l+r>>1;
    build(ls(curr),l,mid);
    build(rs(curr),mid+1,r);
    pushUp(curr);
}

void solve() {
    cin>>n;
    forn(i,1,n) cin>>a[i];
    build();
    cout<<query(1,1,n).ans<<"\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}