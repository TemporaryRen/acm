#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    int sum = 0,x=0;
    vector<int> b;
    for(int i=0;i<s.size();i++){
        int t = s[i] - '0';
        if(t == 3) b.push_back(6);
        if(t == 2) b.push_back(2);
        x *= 10;
        x += t;
        x = x%9;
    }
    int n = b.size();
    vector dp(9,false);
    dp[x] = true;
    for(int i=0;i<n;i++){
        auto ndp = dp;
        int v = b[i];
        for(int k=0;k<9;k++){
            ndp[(k+v)%9] = ndp[(k+v)%9] || dp[k];
        }
        dp = ndp;
    }
    if(dp[0]) cout<<"YES\n";
    else cout<<"NO\n";
    
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