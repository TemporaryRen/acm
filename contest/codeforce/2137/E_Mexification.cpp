#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    map<int,int> cnt;
    ll ssum = 0LL;
    forn(i,0,n){
        cin>>a[i];
        cnt[a[i]] ++;
        ssum += a[i];
    }
    ll target = 0LL;
    int i = 0;
    while(cnt[i] == 1){
        target += i;
        i++;
    }
    int ans = i;
    int ccnt = n - i;
    while(ssum != (target + i * (n-i)) && k > 0){
        ssum = 0LL;
        int start = 0;
        vector<int> b;
        while(cnt[start] > 0){
            if(cnt[start] == 1){
                b.push_back(start);
                ssum += start;
            }
            start ++;
        }
        for(int i=b.size();i<n;i++){
            b.push_back(start);
            ssum += start;
        }
        cnt.clear();
        for(auto x:b) cnt[x]++;
        k--;
        a = b;
    }
    if(cnt[i] == 1){
        cout<<ssum<<"\n";
        return;
    }
    if(k==0){
        cout<<ssum<<"\n";
    }else{
        if(k&1) cout<<target+((ans+1)*ccnt)<<"\n";
        else cout<<target+(ans*ccnt)<<"\n";
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