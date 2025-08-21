#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1e5 + 4;

struct hoilday{
    int f;
    int d;
}a[MX],b[MX],c[MX];

bool myfunction (hoilday i,hoilday j) { return (i.f>j.f); }

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].f;
        a[i].d = i;
    }
    for(int i=0;i<n;i++){
        cin>>b[i].f;
        b[i].d = i;
    }
    for(int i=0;i<n;i++){
        cin>>c[i].f;
        c[i].d = i;
    }

    sort(a,a+n,myfunction);
    sort(b,b+n,myfunction);
    sort(c,c+n,myfunction);
    int ans = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[i].d == b[j].d || a[i].d == c[k].d || c[k].d == b[j].d) continue;
                ans = max(ans,a[i].f + b[j].f + c[k].f);
            }
            
        }
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