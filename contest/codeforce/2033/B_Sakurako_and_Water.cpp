#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector a(n,vector(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int mmin = 0;
        int x=i,y=0;
        while(x<n&&y<n){
            mmin = min(a[x][y],mmin);
            x++;y++;
        } 
        ans -= min(0,mmin);
    }
    for(int j=1;j<n;j++){
        int mmin = 0;
        int x = 0,y=j;
        while(x<n&&y<n){
            mmin = min(a[x][y],mmin);
            x++;y++;
        } 
        ans -= min(0,mmin);
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