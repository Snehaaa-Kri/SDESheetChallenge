class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxi = prices[n-1];
        int maxiprofit = 0;

        for(int i=n-2; i>=0; i--){
            if(prices[i] < maxi){
                int sp = maxi;
                int bp = prices[i];

                maxiprofit = max(maxiprofit, sp-bp);
            }
            maxi = max(prices[i], maxi);
        }
        return maxiprofit;
    }
};