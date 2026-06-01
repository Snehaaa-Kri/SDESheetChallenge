class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());

        int i=0; 
        int j = n-1;

        int mincost = 0;
        while(j>=0){
            mincost+=cost[j];
            j--;
            if(j>=0){
                mincost += cost[j];
            }
            j-=2;
        }
        return mincost;
    }
};