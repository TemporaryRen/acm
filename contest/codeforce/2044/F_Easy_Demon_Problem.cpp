#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    ll sum1 = 0LL,sum2 = 0LL;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum1 += a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        sum2 += b[i];
    }
    set<ll> t1,t2;
    for(int i=0;i<n;i++){
        t1.insert(sum1-a[i]);
    }
    for(int i=0;i<m;i++){
        t2.insert(sum2-b[i]);
    }
    while(q--){
        int x;
        cin>>x;
        bool f = false;
        for(int k=1;k*k<=abs(x);k++){
            if(abs(x)%k != 0) continue;
            if(
                (t1.count(k)&&t2.count(x/k)) ||
                (t2.count(k)&&t1.count(x/k)) ||
                (t2.count(-k)&&t1.count(-x/k)) ||
                (t1.count(-k)&&t2.count(-x/k))
            ){
                // cout<<"match: ";
                // cout<<k<<"\n";
                f = true;
                break;
            }
        
        }
        if(f) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
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
    return 0;
}