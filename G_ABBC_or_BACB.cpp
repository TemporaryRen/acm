#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    string s;cin>>s;
    int n = s.size();
    int cntA = 0,ans = 0;
    vector<int> b;
    forn(i,0,n){
        if(s[i] == 'B'){
            b.push_back(cntA);
            cntA = 0;
        }
        else cntA++;
    }
    b.push_back(cntA);
    sort(all(b));
    forn(i,1,b.size()) ans += b[i];
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