#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n,k;cin>>n>>k;
    vector<int> ans(n);
    int l = 0,r = n-1;
    if(n <= 60 && (1LL << (n-1)) < k){
        cout<<-1<<"\n";
        return;
    }
    for(int i=1;i<n;i++){
        if( n-i-1 <= 60 && (1LL <<(n-i-1)) < k){
            ans[r] = i;
            r --;
            k -= 1LL << (n-i-1);
        }else{
            ans[l] = i;
            l++;
        }
    }
    ans[l] = n;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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