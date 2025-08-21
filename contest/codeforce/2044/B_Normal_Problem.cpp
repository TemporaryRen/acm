#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    string s;
    cin>>s;
    string ans = "";
    for(int i=s.size()-1;i>=0;--i){
        char c = s[i];
        if(c=='p') ans += 'q';
        else if(c=='q') ans += 'p';
        else ans += 'w';
    }
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