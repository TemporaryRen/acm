/*
The original author is a content creator on Bilibil 
see about https://www.bilibili.com/video/BV1ArmpYcEL1?spm_id_from=333.788.videopod.sections&vd_source=82bb775fb6a7ce6a29bd3e3509220efd

*/ 

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define forn(i, a, b) for(int i=a;i<=b;i++)
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)

const int N = 1e5 + 10;
struct Node {
    int len;
    ll sum,add,mul = 1;
} node[N << 2];
ll a[N];
int n, m, M;

#define sum(x) node[x].sum
#define len(x) node[x].len
#define add(x) node[x].add
#define mul(x) node[x].mul

inline void tagAdd(const int curr, const ll v) {
    sum(curr) = (sum(curr) + (v * len(curr)) % M ) % M;
    add(curr) = (add(curr) + v) % M;
}

inline void tagMul(const int curr, const ll v) {
    sum(curr) = v * sum(curr) % M;
    mul(curr) = mul(curr) * v % M;
    add(curr) = add(curr) * v % M;
}

inline void pushUp(const int curr) {
    sum(curr) = sum(ls(curr)) + sum(rs(curr)) % M;
}

inline void pushDown(const int curr) {
    if (mul(curr) != 1) {
        tagMul(ls(curr), mul(curr));
        tagMul(rs(curr), mul(curr));
        mul(curr) = 1;
    }
    if (add(curr)) {
        tagAdd(ls(curr), add(curr));
        tagAdd(rs(curr), add(curr));
        add(curr) = 0;
    }

}

inline void build(const int cur = 1, const int l = 1, const int r = n) {
    len(cur) = r - l + 1;
    if (l == r) {
        sum(cur) = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls(cur), l, mid);
    build(rs(cur), mid + 1, r);
    pushUp(cur);
}

inline ll query(const int curr, const int l, const int r, const int s = 1, const int e = n) {
    if (l <= s and e <= r) return sum(curr);
    pushDown(curr);
    const int mid = s + e >> 1;
    ll ans = 0;
    if (l <= mid) ans += query(ls(curr), l, r, s, mid);
    if (r > mid) ans += query(rs(curr), l, r, mid + 1, e);
    return ans;
}

inline void updateAdd(const int curr, const int l, const int r, const int v, const int s = 1, const int e = n) {
    if (l <= s and e <= r) {
        //range operation
        tagAdd(curr, v);
        return;
    }
    pushDown(curr);
    const int mid = s + e >> 1;
    if (l <= mid) updateAdd(ls(curr), l, r, v, s, mid);
    if (r > mid) updateAdd(rs(curr), l, r, v, mid + 1, e);
    pushUp(curr);
}

inline void updateMul(const int curr, const int l, const int r, const int v, const int s = 1, const int e = n) {
    if (l <= s and e <= r) {
        //range operation
        tagMul(curr, v);
        return;
    }
    pushDown(curr);
    const int mid = s + e >> 1;
    if (l <= mid) updateMul(ls(curr), l, r, v, s, mid);
    if (r > mid) updateMul(rs(curr), l, r, v, mid + 1, e);
    pushUp(curr);
}

void solve() {
    cin >> n >> m >> M;
    forn(i, 1, n) cin >> a[i];
    build();
    while (m--) {
        int oper, x, y, v;
        cin >> oper >> x >> y;
        if (oper == 1) {
            cin >> v;
            updateMul(1, x, y, v);
        }
        if (oper == 2) {
            cin >> v;
            updateAdd(1, x, y, v);
        }
        if (oper == 3) {
            cout << query(1, x, y) % M << "\n";
        }
    }
}

int main() {
    int t = 1;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
