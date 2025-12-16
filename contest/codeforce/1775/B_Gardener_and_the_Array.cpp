#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)
const int MX = 2e5 + 1;
void solve(){
    int n;cin>>n;
    vector<vector<int>> b(n);
    vector<int> c(MX,0);
    forn(i,0,n){
        int k;cin>>k;
        forn(j,0,k){
            int p;cin>>p;
            b[i].push_back(p);
            c[p]++;
        }
    }
    forn(i,0,n){
        auto bb = b[i];
        bool f = true;
        for(auto p : bb){
            if(c[p] == 1){
                f = false;
                break;
            }
        }
        if(f){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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