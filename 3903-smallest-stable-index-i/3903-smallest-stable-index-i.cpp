class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;

        vector<int> suffixmin(n, 0);
        suffixmin[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixmin[i] = min(nums[i], suffixmin[i+1]);
        }
        
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);

            int is = maxi - suffixmin[i];

            if(is<=k) return i;
            
        }
        return -1;
    }
};