#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    forn(i,0,n) cin>>a[i];
    multiset<int> q;
    vector<int> st;
    for(int i=0;i<n;i++){
        int v = a[i];
        while(!st.empty() && v < st.back()){
            q.insert(st.back()+1);
            st.pop_back();
        }
        if(!st.empty() && !q.empty() && *q.begin() < v){
            q.insert(v+1);
        }
        else st.push_back(v);
       
    }
    vector<int> ans;
    forn(i,0,st.size()) ans.push_back(st[i]);
    for(auto x : q) ans.push_back(x);
    for(auto x : ans) cout<<x<<" ";
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