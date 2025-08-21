#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(const string& s){
    int n = s.size();
    vector ret(n,0);
    int l = 0, r = 0;
    for(int i=1;i<n;i++){
        ret[i] = max(0,min(ret[max(0,2*l-i)],r-i));
        while(i+ret[i]+1<n&&i-ret[i]-1>=0&&s[i+ret[i]+1]==s[i-ret[i]-1]) ++ret[i];
        if(i+ret[i]>r){
        l = i;
        r = i+ret[i];
    }
    }
    return ret;
}