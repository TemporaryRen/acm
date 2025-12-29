#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    string s;cin>>s;
    int ans = 0;
    if(s[0] == 'u') ans += 1;
    char pre = 's';
    forn(i,1,s.size()){
        if(pre == 'u' && s[i] == 'u'){
            pre = 's';
            ans++;
        }else{
            pre = s[i];
        }
    }
    if(pre == 'u') ans++;
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