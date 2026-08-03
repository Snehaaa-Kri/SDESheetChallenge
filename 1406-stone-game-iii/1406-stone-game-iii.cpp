class Solution {
public:
    int n;
    int solve(int i, vector<int> &stoneValue, vector<int> &dp){
        if(i>= n) return 0;
        int res = -1e8;

        if(dp[i] != INT_MIN) return dp[i];


        res = max(res, stoneValue[i] - solve(i+1, stoneValue, dp));
        if(i+1 < n) res = max(res, stoneValue[i]+stoneValue[i+1] - solve(i+2, stoneValue, dp));
        if(i+2 < n) res = max(res, stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(i+3, stoneValue, dp));

        return dp[i] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int res = solve(0, stoneValue, dp);

        if(res>0) return "Alice";
        else if(res == 0) return "Tie";
        return "Bob";
    }
};