#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)
const int MX = 1e3 + 5;
int mem[MX][MX];
string a,b,c;
int dfs(int i=0,int j=0){ 
    int ans = 1e9;
    if(mem[i][j] != -1) return mem[i][j];
    if(i==a.size()){
        ans = 0;
        for(int k=j;k<b.size();k++) ans += (b[k] != c[i+k]);
    }
    else if(j==b.size()){
        ans = 0;
        for(int k=i;k<a.size();k++) ans += (a[k] != c[k+j]);
    }
    else ans = min(dfs(i+1,j) + (a[i] != c[i+j]),dfs(i,j+1) + (b[j] != c[i+j]));
    mem[i][j] = ans;
    return ans;
}
void solve(){
    cin>>a>>b>>c;
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            mem[i][j] = -1;
        }
    }
    cout<<dfs()<<"\n";
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