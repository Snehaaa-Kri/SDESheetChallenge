class Solution {
public:

    int solve(int l, int r, vector<int> &ps, vector<vector<int>> &dp){
        if(l>=r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int score = 0;
        for(int mid = l; mid<r; mid++){
            int leftsum = (l-1 >= 0) ? (ps[mid] - ps[l-1]): ps[mid];
            int rightsum =ps[r]-ps[mid];

            if(leftsum < rightsum) {
                score = max(score, leftsum + solve(l, mid, ps, dp));
            }
            else if(rightsum < leftsum){
                score = max(score, rightsum + solve(mid+1, r, ps, dp));
            }
            else{
                score = max({score, leftsum + solve(l, mid, ps, dp), rightsum + solve(mid+1, r, ps, dp)});
            }
        }
        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> ps(n, 0);
        ps[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            ps[i] = ps[i-1]+stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, ps, dp);
        
    }
};