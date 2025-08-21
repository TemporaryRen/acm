#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin>>n;
    vector a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int l = 0,r=1;
    int s = 0;
    int left = 0,right = 1;
    for(;r<n;r++){
        if(r-l==1){
            s=a[l] + a[r];
            continue;
        }
        while(s<=a[r]){
            l += 1;
            s = a[l] + a[l+1];
        }
        if(r-l>1 && s>a[r]){
            if(r-l>right-left){
                left = l;
                right = r;
            }
        }
    }
    int ans = 0;
    cout<<(left)+(n-1-right)<<"\n";
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