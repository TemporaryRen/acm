#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    for(int i=n-2;i>=0;i--){
        if(a[i+1]==0){
            cout<<-1<<"\n";
            return;
        }
        while(a[i] >= a[i+1]) {
            a[i] >>= 1;
            ans ++;
        }
      
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