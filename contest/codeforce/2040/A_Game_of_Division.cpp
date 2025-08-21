#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]%k] ++;
    }
    for(int i=0;i<n;i++){
        if(b[a[i]%k]==1){
            cout<<"YES\n";
            cout<<i+1<<"\n";
            return;
        }
    }
    cout<<"NO\n";
    
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