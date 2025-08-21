#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i] = s[i] - '0';
    for(int i=0;i<n;i++){
        int p = i;
        for(int j=i;j<min(n,i+10);j++){
            if(a[p] - p < a[j] - j){
                p = j;
            }
        }
        for(int j=p;j>i;j--){
            swap(a[j],a[j-1]);
            a[j-1] --;
        }
       
    }
    for(int i=0;i<n;i++) cout<<a[i];
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