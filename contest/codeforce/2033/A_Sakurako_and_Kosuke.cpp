#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;cin>>n;
    if(n&1) cout<<"Kosuke\n";
    else cout<<"Sakurako\n";
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