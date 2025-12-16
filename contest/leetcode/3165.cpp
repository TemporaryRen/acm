#include <bits/stdc++.h>
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        // 1<<0 位置 表示是否包含最左边的节点，1<<1 位置表示是否包含最右边的节点
        vector tree(2<<(__lg(n)+1),std::array{0LL,0LL,0LL,0LL});

        auto merge = [&](int p)->void{
            auto l = tree[p*2+1];
            auto r = tree[p*2+2];
            tree[p][0] = max(l[0] + r[2],l[1] + r[0]) % MOD;
            tree[p][1] = max(l[0] + r[3],l[1]+r[1]) % MOD;
            tree[p][2] = max(l[2] + r[2],l[3]+r[0]) % MOD;
            tree[p][3] = max(l[2]+r[3],l[3]+r[1]) % MOD;
        };

        auto update = [&](auto self,int l,int r,int x,int v,int p)->void{
            if(l==r){
                tree[x][3] = max(0LL,(long long)v);
                return;
            }
            int mid = (l+r) / 2;
            if(p <= mid) self(self,l,mid,x*2+1,v,p);
            if(p > mid) self(self,mid+1,r,x*2+2,v,p);
            merge(x);
        };

        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            update(update,0,n-1,0,x,i);
        }
        long long ans = 0;
        for(auto x : queries){
            update(update, 0,n-1,0,x[1],x[0]);
            ans = (ans + tree[0][3]) % MOD;
        }
        return ans % MOD;
    }
};