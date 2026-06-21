class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost = 0;
        for (int cost : costs) {
            if (cost > max_cost) max_cost = cost;
        }
        
        vector<int> counts(max_cost + 1, 0);
        for (int cost : costs) {
            counts[cost]++;
        }
        
        int total_bars = 0;
        
        for (int price = 1; price <= max_cost; ++price) {
            if (counts[price] == 0) continue;
            
            if (coins < price) break;
            
            int can_buy = min(counts[price], coins / price);
    
            coins -= (long long)can_buy * price;
            total_bars += can_buy;
        }
        
        return total_bars;
    }
};