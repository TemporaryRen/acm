#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,x,ans=0;
    cin>>n;
    for(int i=0;i<n*2;i++){
        cin>>x;
        if(x==1) {
            ans++;
        }
    }
    cout<<ans%2<<" "<<(ans<=n?ans:n*2-ans)<<"\n";
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