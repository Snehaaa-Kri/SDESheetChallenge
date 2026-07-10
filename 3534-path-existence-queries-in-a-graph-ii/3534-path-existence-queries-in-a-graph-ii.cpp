class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int md, vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++) a.push_back({nums[i],i});

        sort(a.begin(),a.end());

        vector<int> pos(n);
        vector<int> val(n);
        for(int i=0;i<n;i++){
            val[i]=a[i].first;
            pos[a[i].second]=i;
        }

        vector<int> dp(n);

        int r=0;
        for(int l=0;l<n;l++){
            while(r<n && val[r]-val[l]<=md) r++;
            dp[l]=r-1;
        }

        vector<vector<int>> up(20,vector<int>(n));

        for(int i=0;i<n;i++)
            up[0][i]=dp[i];

        for(int k=1;k<20;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][up[k-1][i]];
            }
        }

        vector<int> res;

        for(auto &q:queries){
            int u=pos[q[0]];
            int v=pos[q[1]];

            if(u>v) swap(u,v);

            int ans=0;

            for(int k=19;k>=0;k--){
                if(up[k][u]<v){
                    ans+=(1<<k);
                    u=up[k][u];
                }
            }

            if(ans==(1<<20)-1){
                res.push_back(-1);
                continue;
            }

            res.push_back(ans+(u!=v));
        }

        return res;
    }
};