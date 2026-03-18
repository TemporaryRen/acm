#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<char,int> cnt;
    int mmax = 0;
    forn(i,0,n){
        cnt[s[i]]++;
        mmax = max(mmax,cnt[s[i]]);
    }
    int res = max(0,mmax * 2 - n);
    if(n&1) res = max(1,res);
    cout<<res<<"\n";
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