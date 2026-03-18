#include <bits/stdc++.h>
using namespace std;
#define forn(i, l, r) for(int i=l;i<r;i++)
#define for0(i, r, l) for(int i=r;i>l;i--)
#define all(a) a.begin(),a.end()
#define forn(i, l, r) for(int i=l;i<r;i++)


typedef long long ll;


void solve(){
    int n;cin>>n;
    vector a(n,0);
    int tot = 0;
    forn(i,0,n){
        cin>>a[i];
        tot |= a[i];
    }
    int k = 1,l = 0;
    int cur = 0;
    vector bitmask(32,0);
    bool first = true;
    forn(r,0,n){
        cur |= a[r];
        forn(i,0,32){
            if((a[r] >> i)&1) bitmask[i]++;
        }
        if(cur == tot){
            if(first){
                k = max(k,r - l + 1);
                first = false;
            } 
            while(true){
                bool rm = true;
                forn(i,0,32){
                    if((a[l] >> i)&1 && bitmask[i] < 2){
                        rm = false;
                        break;
                    }
                }
                if(rm){
                    bool flat = true;
                    forn(i,0,32){
                        if(((a[r] >> i) & 1) && bitmask[i] == 1){
                            k = max(k,r - l + 1);
                            break;
                        }
                    }
                    forn(i,0,32){
                        if((a[l] >> i)&1) bitmask[i]--;
                    }
                    l++;
                }else{
                    break;
                }
            }
            k = max(k,r - l + 1);
        }
    }

    cout<<k<<"\n";
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