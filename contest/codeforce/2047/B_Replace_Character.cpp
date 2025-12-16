#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<=r;i++)

struct Info{
    char c;
    int v;
};


void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<char,int> cnt;
    for(int i=0;i<n;i++){
        cnt[s[i]] ++;
    }
    vector<Info> l;
    for(auto [k,v] : cnt){
        l.push_back({k,v});
    }
    sort(l.begin(),l.end(),[](const Info a,const Info b){
        return a.v < b.v;
    });
    char t1 = l[0].c;
    char t2 = l[l.size()-1].c;
    for(int i=0;i<n;i++){
        if(s[i] == t1){
            s[i] = t2;
            break;
        }
    }
    cout<<s<<"\n";

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