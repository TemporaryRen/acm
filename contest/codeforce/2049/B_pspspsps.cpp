#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    bool f1 = false,f2 = false;
    forn(i,1,n){
        if(s[i] == 's'){
            f1 = true;
            break;
        }
    } 
    for0(i,n-2,-1){
        if(s[i] == 'p'){
            f2 = true;
            break;
        }
    }
    if(f1 && f2){
        cout<<"NO";
    }else{
        cout<<"YES";
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