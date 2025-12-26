#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n,m;
    cin>>n>>m;
    vector a(n,0);
    forn(i,0,n) cin>>a[i];
    vector b(n,0);iota(all(b),0);
    sort(all(b),[&](int o1,int o2){return a[o1] < a[o2];});
    if(m > n / 2){
        cout<<-1<<"\n";
        return;
    }
    if(m > 0){
        cout<<n - m<<"\n";
        int t = 0;
        forn(i,1,n){
            if(i%2 == 1 || t >= m - 1){
                cout<<b[i] + 1<<" "<<b[i-1] + 1 <<"\n";
            }else t++;
        }
        return;
    }
    ll sum = accumulate(all(a),0LL) - a[b[n-1]];
    if(a[b[n-1]] > sum){
        cout<<-1<<"\n";
        return;
    }
    cout<<n - 1<<"\n";
    int p = n - 2;
    ll tot = a[b[n-2]];
    while(tot < a[b[n-1]]){
        p--;
        tot += a[b[p]];
    }
    forn(i,0,p){
        cout<<b[i] + 1<<" "<<b[i+1] + 1<<"\n";
    }
    forn(i,p,n-1){
        cout<<b[i] + 1<<" "<<b[n-1] + 1<<"\n"; 
    }

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