#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    int left = k-1;
    int right = n-k;
    if(left%2 != right%2 ||(left == 0 && right !=0) || (left != 0 && right ==0)){
        cout<<-1<<"\n";
    }else{
        if(left%2==1 ){
            cout<<3<<"\n";
            cout<<1<<" "<<k<<" "<<(k+1)<<"\n";
        }else{
            if(left == 0 && right == 0){
                cout<<1<<"\n";
                cout<<1<<"\n";
            }else{
                cout<<5<<"\n";
                cout<<1<<" "<<2<<" "<<k<<" "<<(k+1)<<" "<<(k+2)<<"\n";
            }
            
        }
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