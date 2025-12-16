#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector a(n,0);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i] = s.size();
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(m>=a[i]){
            ans ++;
            m -= a[i];
        }
        else break;
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