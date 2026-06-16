class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, INT_MAX));

        //if amout = 0 => coins needed = 0
        for(int i=0; i<n; i++){ //first col
            dp[i][0] = 0;
        }

        //first row
        for(int j=1; j<=amount; j++){
            if(j%coins[0] == 0){
                dp[0][j] = j/coins[0];
            }
        }

        for(int i=1; i<n; i++){
            for(int amt = 1; amt<=amount; amt++){
                int nottake = 0 + dp[i-1][amt];

                int take = INT_MAX;
                if(amt - coins[i] >= 0 && dp[i][amt-coins[i]] != INT_MAX) take = 1+dp[i][amt-coins[i]];


                dp[i][amt] = min(take, nottake);
            }
        }
        return dp[n-1][amount] == INT_MAX? -1: dp[n-1][amount];
    }
};