#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
void solve(){
    int n;cin>>n;
    int mid = -1;
    if(n<5){
        cout<<-1<<"\n";
        return;
    }
    cout<<1<<" "<<3<<" ";
    for(int i=7;i<=n;i+=2) cout<<i<<" ";
    cout<<5<<" "<<4<<" "<<2<<" ";
    for(int i=6;i<=n;i+=2) cout<<i<<" ";
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