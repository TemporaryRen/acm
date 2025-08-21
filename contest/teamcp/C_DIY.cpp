#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    map<int,int> cnt;
    vector<int> b;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        cnt[x] ++;
        if(cnt[x]%2 == 0) b.push_back(x);
    }
    if(b.size() < 4){
        cout<<"NO\n";
        return;
    }
    sort(b.begin(),b.end());
    int ans = 0;
    int m = b.size();
    cout<<"YES\n";
    cout<<b[0]<<" "<<b[1]<<" "<<b[0]<<" "<<b[m-1]<<" "<<b[m-2]<<" "<<b[1]<<" "<<b[m-2]<<" "<<b[m-1]<<"\n";

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