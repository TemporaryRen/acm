#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> cnt;
    forn(i,0,n){
        int x;cin>>x;
        cnt[x] ++;
    }
    for(int i=1;i*i<=(n-2);i++){
        if((n-2)%i==0 && cnt[i] > 0){
            cnt[i]--;
            if(cnt[(n-2)/i] > 0){
                cout<<i<<" "<<(n-2)/i<<"\n";
                return;
            }
        }
    }

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