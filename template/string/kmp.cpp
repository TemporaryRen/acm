#include <bits/stdc++.h>
using namespace std;

vector<int> pi_fun(string s) {
    int n = s.size();
    vector pi(n,0);
    for (int i = 1,j=0; i < n; i++) {
        while (j > 0 && s[i] != s[j])j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}


void kmp(string s,string t){
    auto pi = pi_fun(t);
    int n = s.size();
    int m = t.size();
    int j = 0;
    for(int i=0;i<n;i++){
        char c = s[i];
        while(j>0 && c!=t[j]) j = pi[j-1];
        j += (c==t[j]);
        if(j==m){
            //match success and do something
        }
    }
}