#include <bits/stdc++.h>
using namespace std;

vector<int> Z_fun(string s){
    int n = s.size();
    vector Z(n,0);
    for(int j=1,l=0,r=0;j<n;j++){
        Z[j] = max(0,min(r-j+1,Z[j-l]));
        while(j+Z[j]<n&&s[j+Z[j]]) ++Z[j];
        if(j+Z[j]-1 > r){
            r = j+Z[j]-1;
            l = j;
        }
    }
    return Z;
}