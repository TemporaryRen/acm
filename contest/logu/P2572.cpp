/*
The original author is a content creator on Bilibil 
see about https://www.bilibili.com/video/BV1sCUYYYE14?spm_id_from=333.788.videopod.sections&vd_source=82bb775fb6a7ce6a29bd3e3509220efd

*/ 


#include <bits/stdc++.h>

using namespace std;
#define ls(x) x<<1
#define rs(x) x<<1|1
#define forn(i,a,b) for(int i=a;i<=b;i++)
constexpr int N = 2e5 + 10;
int n,x;
struct Info{
    int len,cnt,pre,suf,ans;

    void operator=(const int val){
        cnt = pre = suf = ans = val;
    }
};

inline Info operator+(const Info& L, const Info& R){
    Info res;
    res.pre = L.pre + (L.pre == L.len ? R.pre : 0);
    res.suf = R.suf + (R.suf == R.len ? L.suf : 0);
    res.cnt = L.cnt + R.cnt;
    res.len = L.len + R.len;
    res.ans = max({L.ans,R.ans,L.suf + R.pre});
    return res;
}
struct Node{
    Info info[2];
    int cov = -1;
    bool rev;
}node[N << 2];

#define info(x,y) node[x].info[y]
#define cov(x) node[x].cov
#define rev(x) node[x].rev
#define len(x,y) info(x,y).len

inline void tagRev(const int curr){
    swap(info(curr,0),info(curr,1));
    rev(curr) = !rev(curr);
}

inline void tagCov(const int curr,const int v){
    info(curr,v)  = len(curr,v),info(curr,v^1) = 0;
    rev(curr) = false,cov(curr) = v;
}
inline void pushDown(const int curr){
    if(cov(curr) != -1){
        tagCov(ls(curr),cov(curr)),tagCov(rs(curr),cov(curr));
        cov(curr) = -1;
    }
    if(rev(curr)){
        tagRev(ls(curr)), tagRev(rs(curr));
        rev(curr) = false;
    }
}
inline void pushUp(const int curr){
    forn(i,0,1) info(curr,i) = info(ls(curr),i) + info(rs(curr),i);
}
inline void update(const int curr,const int l,const int r,const int val =-1,const int s=1,const int e = n){
    if(l<=s and r>=e){
        val == -1 ? tagRev(curr) : tagCov(curr,val);
        return;
    }
    pushDown(curr);
    const int mid = s + e >> 1;
    if(l <= mid) update(ls(curr),l,r,val,s,mid);
    if(r > mid) update(rs(curr),l,r,val,mid+1,e);
    pushUp(curr);
}

inline Info query(const int curr,const int l,const int r,const int s = 1,const int e = n){
    if(l<=s and r>=e) return info(curr,1);
    pushDown(curr);
    const int mid = s + e >> 1;
    if(r <= mid ) return query(ls(curr),l,r,s,mid);
    if(l > mid) return query(rs(curr),l,r,mid+1,e);
    return query(ls(curr),l,r,s,mid) + query(rs(curr),l,r,mid+1,e);
}

inline void build(const int curr = 1,const int l = 1,const int r = n){
    forn(i,0,1) len(curr,i) = r-l+1;
    if(l==r){
        cin>>x;
        info(curr,x) = 1;
        return;
    }
    const int mid = l + r >> 1;
    build(ls(curr),l,mid);
    build(rs(curr),mid+1,r);
    pushUp(curr);
}
void solve() {
    int q;
    cin>>n>>q;
    build();
    while(q--){
        int oper,l,r;
        cin>>oper>>l>>r;
        l++;r++;
        if(oper <= 2) update(1,l,r,oper==2?-1:oper);
        else {
            auto [len,cnt,pre,suf,ans] = query(1,l,r);
            cout<<(oper == 3 ? cnt : ans) <<"\n";
        }
    }
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