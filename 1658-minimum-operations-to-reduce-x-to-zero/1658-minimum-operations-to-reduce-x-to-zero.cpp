class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(auto &el: nums){
            sum += el;
        }

        int target = sum-x;
        if(target < 0) return -1;
        if(target == 0) return n;
        
        int maxi = -1;
        int left = 0;
        int currsum = 0;

        for(int right =0; right<n; right++){
            currsum += nums[right];
            //shrink
            while(left <= right && currsum > target){
                currsum -= nums[left];
                left++;
            }
            if(currsum == target){
                int len = right-left+1;
                maxi = max(maxi, len);
            }
        }

        return (maxi == -1)? -1: (n-maxi);
    }
};